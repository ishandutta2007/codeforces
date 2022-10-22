#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int a=0,fh=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a*fh;
}
#define MN 100005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector
#define mid ((l+r)>>1)
int T,n,m;
int l[MN],r[MN],ans[MN];
vector<int>ad[MN];
const int maxn=MN<<6|5;
int cnt,rt[MN],mn[maxn],ls[maxn],rs[maxn];
const int inf=1e9;
void Ins(int &x,int l,int r,int loc,int v){
	assert(l<=loc&&loc<=r);
	if(!x)x=++cnt;
	mn[x]=min(mn[x],v);
//	cerr<<"ins "<<l<<" "<<r<<" "<<loc<<" "<<v<<endl;
	if(l==r)return;
	if(loc<=mid)Ins(ls[x],l,mid,loc,v);
	else Ins(rs[x],mid+1,r,loc,v);
}
int ask(int x,int l,int r,int b,int e){
	if(l>e||r<b||!x)return inf;
	if(b<=l&&r<=e){
//		cerr<<"OK: "<<l<<" "<<r<<" "<<mn[x]<<endl;
		return mn[x];
	}
	if(r<=mid)return ask(ls[x],l,mid,b,e);
	if(b>mid) return ask(rs[x],mid+1,r,b,e);
	return min(ask(ls[x],l,mid,b,e),ask(rs[x],mid+1,r,b,e));
}
int qry(int l,int r){
	int res=inf,p=r;
	assert(l);
//	cerr<<"qry "<<r<<endl;
	while(r>=l){
		res=min(res,ask(rt[r],1,n,l,p));
		r-=r&(-r);
	}
	return res;
}
void add(int l,int r,int v){
	while(r<=n){
//		cerr<<"ad: "<<r<<endl;
		Ins(rt[r],1,n,l,v);
		r+=r&(-r);
	}
}
int flag;
int work(int l,int r){
	if(r-l+1<flag)return 0;
	int id=qry(l,r);
	if(id>m)return 0;
	assert(l<=::l[id]&&::r[id]<=r);
//	cerr<<"get: "<<id<<" "<<l<<" "<<::l[id]<<" "<<::r[id]<<" "<<r<<endl;
	return ::r[id]-::l[id]+1+work(l,::l[id]-1)+work(::r[id]+1,r);
}
signed main(){
	memset(mn,0x3f,sizeof(mn));
	n=read();m=read();
	for(int i=1;i<=m;++i){
		l[i]=read(),r[i]=read();
		ad[r[i]-l[i]+1].pb(i);
	}
	for(int i=n;i;--i){
		flag=i;
		for(auto j:ad[i]){
			add(l[j],r[j],j);
		}
		ans[i]=work(1,n);
//		cerr<<"fk: "<<i<<" "<<ans[i]<<endl;
	}
	for(int i=1;i<=n;++i)printf("%lld\n",ans[i]);
	return 0;
}