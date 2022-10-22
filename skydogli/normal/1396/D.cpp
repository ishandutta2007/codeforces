#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Mod 1000000007
#define MN 2005
int read(){
	int a=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a;
}
struct data{
	int x,y,c;
	data(int X=0,int Y=0,int C=0){
		x=X;y=Y;c=C;
	}
}w[MN],e[MN];
int n,k,L;
bool cmp(data a,data b){
	return a.x<b.x;
};
bool cmp2(data a,data b){
	return a.y<b.y;
}
int nxt[MN],f[MN];
#define itset multiset<int>::iterator
multiset<int>Set[MN];
int sum[MN<<2],Max[MN<<2],tag[MN<<2];
#define Ls (x<<1)
#define Rs (x<<1|1)
#define mid ((l+r)>>1)
void pushup(int x){
	sum[x]=(sum[Ls]+sum[Rs])%Mod;
	//if(Max[Ls]>Max[Rs])cerr<<"FK: "<<Max[Ls]<<" "<<Max[Rs]<<endl;
	assert(Max[Ls]<=Max[Rs]);
	Max[x]=Max[Rs];
}
void build(int x,int l,int r){
	tag[x]=0;
	if(l==r){sum[x]=f[l]*(e[l].y-e[l-1].y)%Mod;Max[x]=f[l];return;}
	build(Ls,l,mid);
	build(Rs,mid+1,r);
//	cerr<<"now "<<l<<" "<<r<<": ";
	pushup(x);
//	cerr<<Max[x]<<endl;
}
void ptag(int x,int l,int r,int v){
	assert(Max[x]<=v);
	sum[x]=v*(e[r].y-e[l-1].y)%Mod;
	tag[x]=Max[x]=v;
}
void pushdown(int x,int l,int r){
	if(tag[x]){
		ptag(Ls,l,mid,tag[x]);
		ptag(Rs,mid+1,r,tag[x]);
		tag[x]=0;
	}
}
void chkmax(int x,int l,int r,int b,int e,int v){
	if(r<b||l>e)return;
	if(l==r&&Max[x]>v)return;
	if(Max[x]<=v&&b<=l&&r<=e){
		ptag(x,l,r,v);
		return;
	}
	bool flag=(v>Max[Ls]);
	pushdown(x,l,r);
//	cerr<<"?? "<<Max[Ls]<<" "<<Max[Rs]<<" "<<v<<endl;
	chkmax(Ls,l,mid,b,e,v);
	if(flag)
		chkmax(Rs,mid+1,r,b,e,v);
//	cerr<<"FKK"<<endl;
	pushup(x);
}
signed main(){
	n=read();k=read();L=read();
	for(int i=1;i<=n;++i){
		w[i].x=read()+1;w[i].y=read()+1;w[i].c=read();
//		tax[w[i].c].push_back(i);
		e[i]=w[i];
	}
	sort(w+1,w+1+n,cmp);
	sort(e+1,e+1+n,cmp2);
	e[n+1].y=L+1;
	w[n+1].x=w[n+2].x=L+1;
	w[n+1].y=L+1;
	int ans=0;
	for(int i=n;i;--i){
		int tmp=(w[i].x-w[i-1].x);
		if(!tmp)continue;
		multiset<int>S;S.clear();
		for(int i=1;i<=k;++i){
			S.insert(L+1),nxt[i]=L+1;
			Set[i].clear();
			Set[i].insert(L+1);
			Set[i].insert(0);
		}
		for(int j=n;j;--j){
			if(e[j].x>=w[i].x){
				S.erase(S.find(nxt[e[j].c]));
				nxt[e[j].c]=e[j].y;
				S.insert(nxt[e[j].c]);
				Set[e[j].c].insert(e[j].y);
			}
			f[j]=(*(--S.end()));
//			assert(f[j]>=j);
		//	cerr<<w[i].x<<" f "<<j<<" "<<e[j].y<<": "<<f[j]<<endl;
		}
		build(1,1,n);
		for(int j=n+1;j>i;--j){
			if(w[j].c){
				assert(Set[w[j].c].find(w[j].y)!=Set[w[j].c].end());
			//	cerr<<"FKK "<<Set[w[j].c].size()<<endl;
				Set[w[j].c].erase(Set[w[j].c].find(w[j].y));	
				itset it=--Set[w[j].c].upper_bound(w[j].y),ir=it;++ir;
				 
				int ll=lower_bound(e,e+1+n,data(0,*it,0),cmp2)-e;
			//	cerr<<w[j].x<<" c: "<<w[j].c<<" it:"<<(*it)<<" del: "<<ll+1<<" "<<" "<<(*ir)<<endl;
				if(ll)assert(e[ll].y!=e[ll-1].y);
				chkmax(1,1,n,ll+1,n,*ir);
			}
			int res=((L+1)*e[n].y-sum[1]+Mod)%Mod;
		//	cerr<<w[j].x<<"tmp: "<<tmp<<" oh? "<<res<<" "<<w[j].x-w[j-1].x<<endl;
			ans=(ans+(res*tmp%Mod*(w[j].x-w[j-1].x)))%Mod;
		}
	//	cerr<<w[i].x<<" ans: "<<ans<<endl;
//		if(ans==30)break;
	}
	printf("%lld\n",ans);
	return 0;
}