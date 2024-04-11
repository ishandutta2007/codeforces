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
 		int n,p,k; cin >> n >> p >> k;
 		vector<pii>a(n+1);
 		rep(i,1,n+1){
 			cin >> a[i].x;
 			a[i].y = i;
 		}
 		sort(a.begin()+1,a.end(),greater<pii>());
 		vector<vector<int>>vec(n+1,vector<int>(p));
 		rep(i,1,n+1){
 			rep(j,0,p){
 				cin >> vec[i][j];
 			}
 		}
 		vector<vector<int>>dp(n+1,vector<int>(1 << p,-1e18));
 		int ans = 0;
 		dp[0][0] = 0;
 		for(int i = 1; i <= n; i++){
 			for(int mask = 0; mask < (1 << p); mask++){
 				int cnt = 0;
 				for(int j = 0; j < p; j++){
 					if((1 << j)&mask){
 						cnt++;
 						maxs(dp[i][mask],vec[a[i].y][j] + dp[i-1][mask^(1 << j)]);
 					}
 				}
 				if(i - 1 - cnt < k){
 					maxs(dp[i][mask],dp[i-1][mask] + a[i].x);
 				}
 				else{
 					maxs(dp[i][mask],dp[i-1][mask]);
 				}
 			}
 			
 		}
 		cout << dp[n].back() << endl;
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