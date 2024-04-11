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
 		int n,k; cin >> n >> k;
 		vector<int> t1 = {0},t2 = {0};
 		for(int i = 1; i <= n; i++){
 			int x; cin >> x;
 			if(x > 0){
 				t1.push_back(x);
 			}else if(x < 0){
 				t2.push_back(-x);
 			}
 		}
 		sort(all(t1));
 		sort(all(t2));
 		int ans = 0;
 		auto solve = [&](vector<int> a){
 			int n = a.size();n--;
 			vector<int> dp(n + 1);
 			dp[0] = 0;
 			deque<pii> dq;
 			dq.push_back({0,0});
 			for(int i = 1; i <= n; i++){
 				while(!dq.empty() and i - dq.front().y > k)dq.pop_front();
 				dp[i] = dq.front().x + a[i];
 				while(!dq.empty() and dq.back().x > dp[i] + a[i])dq.pop_back();
 				dq.push_back({dp[i] + a[i],i});
 			}
 			ans += dp[n];
 		};
 		solve(t1);
 		solve(t2);
 		if(sz(t1) > 0 and sz(t2) > 0){
 			ans += min(t1.back(),t2.back());
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