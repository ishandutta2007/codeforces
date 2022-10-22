#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
#define pb push_back
using std::cin;
using std::cout;

typedef unsigned long long u64;
typedef double db;
typedef long long ll;
typedef unsigned u32;
int n, m, k, q;
const int N=200200;
std::vector<int> a[N],b[N];
struct T{ int l,r,x,id; };
std::vector<T> a0[N],a1[N];
int ans[N];
const int L=1<<17;
int sgt[L<<1];
inline void upt(int x,int v){
	for(sgt[x+=L]=v;x>>=1;)sgt[x]=std::min(sgt[x<<1],sgt[x<<1|1]);
}
inline int ask(int l,int r){
	int res=1e9;
	for(l+=L-1,r+=L+1;l+1!=r;l>>=1,r>>=1){
		if((l&1)==0)res=std::min(res,sgt[l^1]);
		if((r&1)==1)res=std::min(res,sgt[r^1]);
	}
	return res;
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m >> k >> q;
	rep(i, 1, k) {
		int x, y; cin >> x >> y;
		a[x].pb(y),b[y].pb(x);
	}
	rep(i,1,q){
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		a0[x2].pb({y1,y2,x1,i});
		a1[y2].pb({x1,x2,y1,i});
		ans[i]=0;
	}
	rep(i,1,n){
		for(auto x:a[i])upt(x,i);
		for(auto x:a0[i])ans[x.id]|=ask(x.l,x.r)>=x.x;
	}
	memset(sgt,0,sizeof sgt);
	rep(i,1,m){
		for(auto x:b[i])upt(x,i);
		for(auto x:a1[i])ans[x.id]|=ask(x.l,x.r)>=x.x;
	}
	rep(i,1,q){
		cout<<(ans[i]?"YES":"NO")<<'\n';
	}
}