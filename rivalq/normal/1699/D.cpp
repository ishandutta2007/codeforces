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
 		for(int i = 1; i <= n; i++){
 			cin >> a[i];
 		}
 		vector<int>dp(n + 2,-1e9);
 		vector<vector<int>>fr(n + 1,vector<int>(n + 1));
 		for(int i = 1; i <= n; i++){
 			int mx = 1;
 			vector<int> t(n + 1);
 			for(int j = i; j <= n; j++){
 				t[a[j]]++;
 				maxs(mx,t[a[j]]);
 				fr[i][j] = mx;
 			}
 		}

 		auto check = [&](int i,int j){
 			if(i > j)return true;
 			int len = j - i + 1;
 			if(2*fr[i][j] <= len and len % 2 == 0)return true;
 			return false;
 		};

 		for(int i = 1; i <= n + 1; i++){
 			if(check(1,i - 1))dp[i] = 1;
 			for(int j = i - 1; j >= 1; j--){
 				if((i == n + 1 or a[i] == a[j]) and check(j + 1,i - 1)){
 					maxs(dp[i],dp[j] + 1);
 				}
 			}
 		}
 		cout << dp[n + 1] - 1 << endl;
 		
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