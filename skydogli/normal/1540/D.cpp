#include<bits/stdc++.h>
using namespace std;
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
#define vc vector<int>
int n,a[MN],b[MN],q;
int blk,T;
int loc(int x){
	return (x-1)/blk+1;
}
vector<int >pos[MN],dt[MN];
pii mn[MN];
int sum[MN];
const int inf=1e9;
#define Ls (x<<1)
#define Rs (x<<1|1)
#define mid ((l+r)>>1)
pii operator -(pii a,int b){return mp(a.x-b,a.y);}
void pushup(int x){
	sum[x]=sum[Ls]+sum[Rs];
	mn[x]=min(mn[Ls],mn[Rs]-sum[Ls]);
}
void Build(int x,int l,int r){
	sum[x]=0;
	if(l==r){mn[x]=mp(a[l],l);return;}
	Build(Ls,l,mid);
	Build(Rs,mid+1,r);
	pushup(x);
}
void del(int x,int l,int r,int loc){
	if(l==r){mn[x]=mp(inf,0);sum[x]=1;return;}
	if(loc<=mid)del(Ls,l,mid,loc);
	else del(Rs,mid+1,r,loc);
	pushup(x);
}
void build(int x){
	int L=(x-1)*blk+1,R=min(x*blk,n);
	int now=0,ad=0;
	pos[x].clear();dt[x].clear();
	Build(1,L,R);
	while(now<=n){
		while(mn[1].x<=now){
			int p=mn[1].y;
			del(1,L,R,p);
			ad++;
		}
		pos[x].pb(now);
		dt[x].pb(ad);
		now=mn[1].x;
	}
	pos[x].pb(n+1);
	assert(pos[x].size()<=blk+2);
}
signed main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=i-read();
	}
//	blk=sqrt(n*(log2(n)+1)+1);
	blk=pow(n*(log2(n)+1)+1,0.3334);
//	blk=sqrt(n);
	T=(n-1)/blk+1;
	for(int i=1;i<=T;++i)build(i);
	q=read();
//	cerr<<"done"<<endl;
	for(int i=1;i<=q;++i){
//		if(i%10000==0)cerr<<"OK: "<<i<<endl;
		int o=read();
		if(o==1){
			int x=read(),v=read();a[x]=x-v;
			build(loc(x));
		}
		else{
			int x=read(),v=a[x];
			int p=loc(x),r=min(n,p*blk);
			for(int i=x+1;i<=r;++i)if(a[i]<=v)v++;
			for(int i=p+1;i<=T;++i){
				int o=upper_bound(pos[i].begin(),pos[i].end(),v)-pos[i].begin()-1;
				v+=dt[i][o];
			}
			printf("%d\n",v);
		}
	}
	return 0;
}