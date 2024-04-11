#include<bits/stdc++.h>
using namespace std;
#define MN 200005
#define LL long long
#define mp make_pair
#define fir first
#define sec second
#define pii pair<int,int>
inline void chkmax(int &a,int b){if(a<b)a=b;}
inline void chkmin(int &a,int b){if(a>b)a=b;}
inline int read(){
	   int a=0,fh=1;char c=getchar();
	   while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	   while('0'<=c&&c<='9'){
		   a=a*10+c-48;
		   c=getchar();
	   }
	   return a*fh;
}
#define Ls (x<<1)
#define Rs (x<<1|1)
#define mid ((l+r)>>1)
int n,a[MN];
vector<int>loc[MN];
int Max[MN<<2],Min[MN<<2],tag[MN<<2];
LL sum[MN<<2],h[MN];
void build(int x,int l,int r){
	if(l==r){Min[x]=Max[x]=sum[x]=l;return;}
	build(Ls,l,mid);
	build(Rs,mid+1,r);
	sum[x]=sum[Ls]+sum[Rs];
	Max[x]=max(Max[Ls],Max[Rs]);
	Min[x]=min(Min[Ls],Min[Rs]);
}
void upd(int x,int l,int r,int v){
	Min[x]=Max[x]=tag[x]=v;
	sum[x]=(LL)v*(r-l+1);
}
void pd(int x,int l,int r){
	if(tag[x]){
		upd(Ls,l,mid,tag[x]);
		upd(Rs,mid+1,r,tag[x]);
		tag[x]=0;
	}
}
void change(int x,int l,int r,int b,int e,int v){
	if(l>r||l>e||r<b||Min[x]>v)return;
	if(Max[x]<=v&&b<=l&&r<=e){
		upd(x,l,r,v);
	//	cerr<<"chg: "<<l<<" "<<r<<" "<<v<<endl;
		return;
	}
	pd(x,l,r);
	if(b<=mid)change(Ls,l,mid,b,e,v);
	if(e>mid)change(Rs,mid+1,r,b,e,v);
	sum[x]=sum[Ls]+sum[Rs];
	Max[x]=max(Max[Ls],Max[Rs]);
	Min[x]=min(Min[Ls],Min[Rs]);
}
int main(){
	n=read();
	int N=0;
	for(int i=1;i<=n;++i){
		a[i]=read();
		loc[a[i]].push_back(i);
		N=max(N,a[i]);
	}
	build(1,1,n);
	for(int i=1;i<=N;++i){
		for(int j=i*2;j<=N;j+=i)
			for(int k=0;k<loc[j].size();++k)
				loc[i].push_back(loc[j][k]);
		sort(loc[i].begin(),loc[i].end());
	}
	for(int i=N;i>=0;--i){
		h[i]=(LL)n*(n+1)-sum[1];
	//	cerr<<i<<": "<<h[i]<<endl;
		if(loc[i].size()<2)continue;
		int len=loc[i].size();
		int l1=loc[i][0],l2=loc[i][1],r1=loc[i][len-1],r2=loc[i][len-2];
		change(1,1,n,l2+1,n,n+1);
		change(1,1,n,l1+1,l2,r1);
		change(1,1,n,1,l1,r2);
	}
	LL ans=0;
	for(int i=1;i<=N;++i)ans+=(h[i]-h[i-1])*i;
	printf("%lld\n",ans);
	return 0;
}