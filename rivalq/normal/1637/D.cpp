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
 		vector<int>a(n + 1),b(n + 1);
 		int ans = 0;
 		int sum = 0;
 		for(int i = 1; i <= n; i++){
 			cin >> a[i];
 			ans += (n - 2)*a[i]*a[i];
 			sum += a[i];
 		}
 		for(int i = 1; i <= n; i++){
 			cin >> b[i];
 			ans += (n - 2)*b[i]*b[i];
 			sum += b[i];
 		}
 		vector<int>dp(sum + 1);
 		dp[0] = 1;
 		for(int i = 1; i <= n; i++){
 			vector<int>f(sum + 1);
 			for(int j = 0; j <= sum; j++){
 				if(a[i] <= j)f[j] |= dp[j - a[i]];
 				if(b[i] <= j)f[j] |= dp[j - b[i]];
 			}
 			swap(f,dp);
 		}
 		int mn = sum*sum;
 		for(int i = 0; i <= sum; i++){
 			if(dp[i]){
 				mins(mn,i*i+(sum-i)*(sum-i));
 			}
 		}
 		cout << mn + ans << endl;
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