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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int M = 1e9;

int solve(){
 		int n; cin >> n;
 		vector<int> a(n + 1);
 		int cnt = 0;
 		int cnt1 = 0,cnt2 = 0;
 		int low = 0;
 		for(int i = 1; i <= n; i++){
 			cin >> a[i];
 			if(a[i] == 1)low = 1;
 			maxs(cnt,a[i] / 3);
 			if(a[i] % 3 == 1)cnt1 = 1;
 			else if(a[i] % 3 == 2)cnt2 = 1;
 		}
 		int ans = cnt + cnt1 + cnt2;
 		for(int j = cnt - 1; j >= max(0LL,cnt - 3); j--){
 			for(int ones = low; ones <= 1; ones++){
 				int m = 0;
	 			for(int i = 1; i <= n; i++){
	 				int val = a[i];
	 				val = max(val % 3, val - 3*j);
	 				int res = LLONG_MAX;
	 				if(val % 2 and ones == 0){
	 					mins(res,(val + 3)/2);
	 				}else{
	 					mins(res, val / 2);
	 				}
	 				if(ones == 1){
	 					int val = a[i] - 1;
		 				val = max(val % 3, val - 3*j);
		 				if(val % 2){
		 					mins(res, (val + 3)/2);
		 				}else{
		 					mins(res, val / 2);
		 				}
	 				}
	 				maxs(m,res);
	 				
	 			}
 				mins(ans,j + ones + m);
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