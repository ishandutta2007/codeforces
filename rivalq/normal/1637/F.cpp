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


int solve(){
 		int n; cin >> n;
 		vector<int>a(n + 1);
 		vector<vector<int>>g(n + 1);

 		for(int i = 1; i <= n; i++){
 			cin >> a[i];
 		}
 		int r = 1;
 		for(int i = 2; i <= n; i++){
 			int u,v; cin >> u >> v;
 			g[u].push_back(v);
 			g[v].push_back(u);
 		}
 		if(n == 2){
 			cout << 2*max(a[1],a[2]) << endl;
 			return 0;
 		}
 		vector<int> in(n + 1),out(n + 1),eu(n + 1),pre(n + 1),suff(n + 1),sub(n + 1);
 		int t = 0;
 		function<void(int,int)> dfs = [&](int u,int p){
 			in[u] = ++t;
 			eu[t] = a[u];
 			sub[u] = a[u];
 			for(auto i:g[u]){
 				if(i != p){
 					dfs(i,u);
 					sub[u] = max(sub[u],sub[i]);
 				}
 			}
 			out[u] = t;
 		};
 		while(g[r].size() == 1)r++;
 		dfs(r,r);
 		pre = eu;
 		suff = eu;
 		for(int i = 2; i <= n; i++)maxs(pre[i],pre[i - 1]);
 		for(int i = n - 1; i >= 1; i--)maxs(suff[i],suff[i + 1]);
 		suff.push_back(0);
 		int ans = 0;
 		function<void(int,int)> dfs2 = [&](int u,int p){
 			vector<int> vec;
 			for(auto i:g[u]){
 				if(i != p){
 					vec.push_back(sub[i]);
 					dfs2(i,u);
 				}
 			}
 			sort(all(vec));
 			if(u == p){
 				ans += max(0LL,a[u] - vec.back());vec.pop_back();
 				ans += max(0LL,a[u] - vec.back());vec.pop_back();
 			}else if(vec.size() >= 1){
 				int mx = pre[in[u] - 1];
 				maxs(mx,suff[out[u] + 1]);
 				vec.push_back(mx);
 				sort(all(vec));
 				ans += max(0LL,a[u] - vec.back());vec.pop_back();
 				ans += max(0LL,a[u] - vec.back());vec.pop_back();
 			}else{
 				int mx = pre[in[u] - 1];
 				maxs(mx,suff[out[u] + 1]);
 				ans += max(0LL,a[u] - mx);
 				ans += a[u];
 			}
 		};
 		dfs2(r,r);
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
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}