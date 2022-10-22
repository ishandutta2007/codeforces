#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int a=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}	
	return a;
}
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define MN 100005
const int N=2000000000;
int n,m,a[MN],ans[MN*3],val[MN];
vector<pii >tag[MN];
int bMin[MN],lst[MN];
void add(int x,int v){
	while(x){
		bMin[x]=min(bMin[x],v);
		x-=x&(-x);
	}
}
int ask(int x){
	int res=1e9;
	while(x<=n){
		res=min(res,bMin[x]);
		x+=x&(-x);
	}
	return res;
}
#define mid ((l+r)>>1)
#define maxn 5000005
int Min[maxn],Max[maxn],ls[maxn],rs[maxn],cnt,rt;
void Ins(int &x,int l,int r,int loc,int v){
	if(!x){x=++cnt;Max[x]=ls[x]=rs[x]=0;Min[x]=1e9;}
	if(l==r){Min[x]=Max[x]=v;return;}
	if(loc<=mid)Ins(ls[x],l,mid,loc,v);
	else Ins(rs[x],mid+1,r,loc,v);
	Min[x]=min(Min[ls[x]],Min[rs[x]]);
	Max[x]=max(Max[ls[x]],Max[rs[x]]);
}
int FK;
int qry(int &x,int l,int r,int b,int e){
	if(!x)return 0;
	if(b<=l&&r<=e)return Max[x];
	if(l>e||r<b)return 0;
	return max(qry(ls[x],l,mid,b,e),qry(rs[x],mid+1,r,b,e));
}
int TOT=0;
void upd(int x,int v,int Minv){
//	cerr<<"upd: "<<x<<" "<<v<<endl;
	if(x<1||a[x]<v)return;
	if(val[x]>a[x]-v){
		add(x,val[x]=a[x]-v);
	}	
	if(a[x]==v)return;
	int to=qry(rt,0,N,v*2,a[x]+v);
	assert(to<x);
	upd(to,v,min(Minv,a[x]-v));
}
void solve(){
	cnt=0;rt=0;
	for(int i=1;i<=n;++i)bMin[i]=val[i]=1e9;
	for(int i=1;i<=n;++i){
//		cerr<<i<<" "<<a[i]<<endl;
	//	if(i%1000==0)cerr<<"done: "<<i<<" "<<TOT<<" "<<FK<<endl;
		int p=i-1;
		while(p&&a[p]<a[i])p=lst[p];
		lst[i]=p;
		upd(p,a[i],1e9);
		Ins(rt,0,N,a[i]*2,i);
		for(int j=0;j<tag[i].size();++j){
			ans[tag[i][j].y]=min(ans[tag[i][j].y],ask(tag[i][j].x));
		}
	}
}
signed main(){
//	freopen("fk.in","r",stdin);
//	freopen("fk.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
//		cerr<<i<<": "<<a[i]<<endl;
	}
	m=read();
	for(int i=1;i<=m;++i){
		int l=read(),r=read();	
		tag[r].push_back(mp(l,i));
		ans[i]=1e9;
	}
	solve();
//	return 0;
	int nn=1000000000;
	for(int i=1;i<=n;++i)a[i]=nn-a[i];
	solve();
	for(int i=1;i<=m;++i)printf("%lld\n",ans[i]);
	return 0;
}