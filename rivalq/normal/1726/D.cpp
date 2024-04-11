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

const int maxn = 2000005;
int p[maxn];
int sz[maxn];
int cnt = 0;
void clear(int n){
    rep(i,0,n)p[i]=i,sz[i]=1;
}
int root(int x){
   while(x!=p[x]){
       p[x]=p[p[x]];
       x=p[x];
   }
   return x;  
}
void merge(int x,int y){
    int p1=root(x);
    int p2=root(y);
    if(p1==p2)return;
    cnt--;
    if(sz[p1]>=sz[p2]){
        p[p2]=p1;
        sz[p1]+=sz[p2];
    }
    else{
        p[p1]=p2;
        sz[p2]+=sz[p1];
    }
}

int calc(vector<pii> edges,int n){
	clear(n + 1);
	cnt = n;
	for(auto [u,v]:edges)merge(u,v);
	return cnt;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int solve(){
 		int n,m; cin >> n >> m;

 		vector<pii> edges;
 		vector<vector<int>>g(n + 1);
 		map<pii,int> mp;
 		vector<pii> st;
 		for(int i = 1; i <= m; i++){
 			int a,b; cin >> a >> b;
 			g[a].push_back(b);
 			g[b].push_back(a);
 			if(a > b)swap(a,b);
 			st.push_back({a,b});
 			mp[{a,b}] = i - 1;
 		}
 		vector<int> vis(n + 1);
 		function<void(int,int)> dfs = [&](int u,int p){
 				vis[u] = 1;
	 			for(auto i:g[u]){
	 				if(i != p){
	 					if(vis[i] == 1){
	 						edges.push_back({min(i,u),max(i,u)});
	 					}else if(!vis[i]){
	 						dfs(i,u);
	 					}
	 				}
	 			}
	 			vis[u] = 2;
 		};


 		int k = 50;
 		string ans(m,'0');
 		int can = m - n + 1;
 		while(k--){
 			ans = string(m,'0');
 			int j = rng()%n + 1;
 			edges.clear();
 			vis.clear();
 			vis.resize(n + 1);
 			dfs(j,j);
 			cnt = n;
 			clear(n + 1);
 			for(auto [u,v]:edges){
 				assert(mp.count({u,v}));
 				ans[mp[{u,v}]] = '1';
 				merge(u,v);
 			}
 			if(cnt == n - can){
 				cout << ans << endl;
 				return 0;
 			}
 		}
 		cout << ans << endl;



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
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}