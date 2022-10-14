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
 		int n,m; cin >> n >> m;
 		vector<int> dp(n + 1);
 		vector<int> pre(n + 1);
 		dp[1] = 1;
 		int s = 1;
 		for(int z = 2; z <= n; z++){
 			int l = z;
 			int r = 2*z;
 			pre[l]++;
 			if(r <= n)pre[r]--;
 		}
 		for(int i = 2; i <= n; i++){
 			dp[i] = (dp[i] + s)%m;
 			pre[i] = (pre[i] + pre[i - 1])%m;
 			dp[i] = (dp[i] + pre[i])%m;
 			if(dp[i] < 0)dp[i] += m;
 			for(int z = 2; z*i <= n; z++){
 				int l = z*i;
 				int r = z*i + z;
 				pre[l] = (pre[l] + dp[i])%m;
 				if(r <= n)pre[r] = (pre[r] - dp[i])%m;
 			}
 			s = (s + dp[i])%m;
 		}
 		cout << dp[n] << endl;
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