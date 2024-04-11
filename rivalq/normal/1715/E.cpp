// Jai Shree Ram  
  
#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC



template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}

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
}cht;


int solve(){
 		int n,m,k; cin >> n >> m >> k;

 		vector<vector<pii>> g(n + 1);
 		for(int i = 1; i <= m; i++){
 			int a,b,c; cin >> a >> b >> c;
 			g[a].push_back({b,c});
 			g[b].push_back({a,c});
 		}
 		vector<int> dis(n + 1,1e15);
 		dis[1] = 0;
 		for(int i = 1; i <= k + 1; i++){
 			priority_queue<pii> pq;
 			for(int i = 1; i <= n; i++){
 				pq.push({-dis[i],i});
 			}
 			vector<int> vis(n + 1);
 			while(!pq.empty()){
 				auto [w,u] = pq.top();
 				pq.pop();
 				w *= -1;
 				if(vis[u])continue;
 				vis[u] = 1;
 				for(auto [v,d]:g[u]){
 					if(dis[v] > dis[u] + d){
 						dis[v] = dis[u] + d;
 						pq.push({-dis[v],v});
 					}
 				}
 			}
 			if(i <= k){
 				LineContainer lc;
 				for(int i = 1; i <= n; i++){
 					lc.add(2*i,-dis[i] - i*i);
 				}
 				for(int i = 1; i <= n; i++){
 					dis[i] = -lc.query(i) + i*i; 
 				}	
 			}
 		}
 		for(int i = 1; i <= n; i++)cout << dis[i] << " ";cout << endl;

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