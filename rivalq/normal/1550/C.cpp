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
 		rep(i,1,n+1){
 			cin >> a[i];
 		}
 		auto is = [&](vector<int>&t){
 			int n = t.size();
 			vector<int> prefix_mn(n),suffix_mx(n);
 			prefix_mn[0] = t[0];
 			for(int i = 1; i < n; i++){
 				prefix_mn[i] = min(prefix_mn[i-1],t[i]);
 			}
 			suffix_mx[n - 1] = t[n - 1];
 			for(int i = n - 2; i >= 0; i--){
 				suffix_mx[i] = max(suffix_mx[i + 1],t[i]);
 			}
 			for(int i = 1; i + 1  < n;i++){
 				if(prefix_mn[i - 1] <= t[i] and t[i] <= suffix_mx[i + 1])return 0;
 			}
 			return 1;
 		};
 		auto check = [&](int l,int r){
 			if(r - l + 1 <= 2)return 1LL;
 			vector<int>t,t2;
 			for(int i = l; i <= r; i++){
 				t.push_back(a[i]);
 				t2.push_back(-a[i]);
 			}
 			return (int)(is(t) && is(t2));
 		};
 		int ans = 0;
 		for(int i = 1; i <= n; i++){
 			for(int j = i; j <= n; j++){
 				if(j - i + 1 > 10)break;
 				ans += check(i,j);
 				//cout << i << " " << j << " "<< check(i,j) << endl;
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