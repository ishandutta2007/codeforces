#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define eb             emplace_back
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC
using namespace std;


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}



bool Q;
struct Line {
	mutable int k, m, p;
	 bool operator<(const Line& o) const {
        return Q ? p < o.p : k < o.k;
    }
};
struct LineContainer : multiset<Line> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	const int inf = LLONG_MAX;
	int div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(int k, int m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	int query(int x) {
		assert(!empty());Q=1;
		auto l = *lower_bound({0,0,x});Q=0;
		return l.k * x + l.m;
	}
};
const int maxn=100005;
int a[maxn];
int b[maxn];
int sz[maxn];
int dp[maxn];
vector<int>g[maxn];
vector<int>vec[maxn];
LineContainer lc[maxn];
void dfs1(int u=1,int p=0){
	sz[u]++;
	for(auto i:g[u]){
		if(i!=p)dfs1(i,u),sz[u]+=sz[i];
	}
}
void dfs2(int u=1,int p=0,bool keep=1){
	 if(sz(g[u])==1 && u!=1){
	 	vec[u].pb(u);
	 	lc[u].add(-b[u],0);
	 	return;
	 }
	 int mx=-1,big=-1;
	 for(auto i:g[u]){
	 	if(i!=p && mx<sz[i])mx=sz[i],big=i;
	 }
	 for(auto i:g[u]){
	 	if(i!=p && i!=big)dfs2(i,u,0);
	 }
	 if(big!=-1){
	 	dfs2(big,u,1);
	 	swap(lc[u],lc[big]);
	 	swap(vec[u],vec[big]);
	 }
	 vec[u].pb(u);
	 for(auto i:g[u]){
	 	if(i!=p && i!=big){
	 		for(auto j:vec[i]){
	 			vec[u].pb(j);
	 			lc[u].add(-b[j],dp[j]);
	 		}
	 	}
	 }
	 dp[u]=lc[u].query(a[u]);
	 lc[u].add(-b[u],dp[u]);
}
int solve(){
 int n;cin>>n;
 rep(i,1,n+1)cin>>a[i];
 rep(i,1,n+1)cin>>b[i];
 rep3(n-1){
 	int a,b;cin>>a>>b;
 	g[a].pb(b);
 	g[b].pb(a);
 }
 dfs1();
 dfs2();
 for(int i=1;i<=n;i++)cout<<-dp[i]<<" ";cout<<endl;
 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef SIEVE
    sieve();
    #endif
    #ifdef NCR
    init();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}