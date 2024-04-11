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

#define double long double

const double eps = 1e-7;

int solve(){
 		int k,q; cin >> k >> q;
 		int n = 10000;
 		vector<vector<double>>dp(n+1,vector<double>(k+1));
 		dp[1][1] = 1;
 		for(int i = 2; i <= n; i++){
 			for(int j = 1; j <= k; j++){
 				double p = j;
 				p /= k;
 				dp[i][j] += dp[i-1][j]*(p);
 				p = (k - j +1);
 				p /= k;
 				dp[i][j] += dp[i-1][j-1]*(p);
 			}
 		}
 		while(q--){
 			int p; cin >> p;
 			int j = n;
 			for(int i = k; i <= n; i++){
 				//p - eps >= 2000*dp[i][k]
 				if(p - eps <= 2000*dp[i][k]){
 					j = i;
 					//cout << "found" << endl;
 					break;
 				}
 			}
 			cout << j << endl;
 		}
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