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
const int maxn=150005;
int ctree[maxn];
int sz[maxn];
int temp=0;
int vis[maxn];
vector<int>g[maxn];
vector<pii>temp1,temp2;
int a[maxn];
// for max
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
}cht1,cht2;
int ans=0;
/**** CENTROID DECOMPOSITION****/
void dfs1(int u,int par){
	 sz[u]=1;
	 temp++;
	 for(auto i:g[u]){
	 	if(i!=par && !vis[i]){
            dfs1(i,u);
            sz[u]+=sz[i];
	 	}
	 }
}
int dfs2(int u,int par){
	 for(auto i:g[u]){
	 	if(i!=par && sz[i]>temp/2 && !vis[i]){
             return dfs2(i,u);
	 	}
	 }
	 return u;
}
//pre1 -->towards centroid
//pre2 -->towards vertices
void dfs3(int u,int p,int l,int sum,int pre1,int pre2,int centroid){
     sum+=a[u];
     pre1+=(l+1)*a[u];
     pre2+=sum;
     maxs(ans,pre1+cht2.query(sum));
     maxs(ans,pre2+cht1.query(l+1));
     maxs(ans,pre1);
     maxs(ans,pre2);
     temp1.pb({pre1-sum,sum-a[centroid]});
     temp2.pb({pre2-(l+1)*a[centroid],l});
     for(auto i:g[u]){
     	if(i!=p && !vis[i])dfs3(i,u,l+1,sum,pre1,pre2,centroid);
     } 
}
void decompose(int u,int par){
   temp=0;
   cht1.clear();
   cht2.clear();
   cht1.add(0,0);
   cht2.add(0,0);
   dfs1(u,u);
   int centroid=dfs2(u,u);
   if(par==-1)par=u;
   ctree[centroid]=par;
   vis[centroid]=1;
   for(auto i:g[centroid]){
      if(vis[i])continue;
      dfs3(i,centroid,1,a[centroid],a[centroid],a[centroid],centroid);
      for(auto j:temp1)cht1.add(j.y,j.x);
      for(auto j:temp2)cht2.add(j.y,j.x);
      temp1.clear();
      temp2.clear();	
   }
   for(auto i:g[centroid]){
   	  if(vis[i])continue;
   	  decompose(i,centroid);
   } 
   g[centroid].clear();
}

int solve(){
 int n;cin>>n;
 rep3(n-1){
 	int a,b;cin>>a>>b;
 	g[a].pb(b);
 	g[b].pb(a);
 }
 rep(i,1,n+1)cin>>a[i];
 decompose(1,-1);
 cout<<ans<<endl;
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