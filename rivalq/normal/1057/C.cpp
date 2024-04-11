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
 		int n,s,k; cin >> n >> s >> k;
 		vector<int>a(n + 1);
 		string colors; 
 		vector<vector<int>> g(n + 1);

 		for(int i = 1; i <= n; i++){
 			cin >> a[i];
 		}
 		cin >> colors;
 		for(int i = 1;  i <= n; i++){
 			for(int j = 1; j <= n; j++){
 				if(colors[i - 1] != colors[j - 1] and a[j] > a[i]){
 					g[i].push_back(j);
 				}
 			}
 		}

 		vector<vector<int>> dp(n + 1,vector<int>(k + 1,-1));
 		function<int(int,int)> dfs = [&](int u,int k){
 			if(dp[u][k] != -1)return dp[u][k];
 			int &ans = dp[u][k];
 			ans = INT_MAX;
 			k -= a[u];
 			if(k <= 0) {
 				return ans = 0;
 			}
 			for(auto i:g[u]){
 				ans = min(ans,dfs(i,k) + abs(i - u));
 			}
 			return ans;
 		};
 		int ans = INT_MAX;
 		for(int i = 1; i <= n; i++){
 			mins(ans,dfs(i,k) + abs(s - i));
 		}
 		if(ans == INT_MAX)ans = -1;
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