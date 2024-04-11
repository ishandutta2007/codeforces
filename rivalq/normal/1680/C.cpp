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
 		string s; cin >> s;
 		int n = s.length();
 		vector<int> pref(n + 1);
 		for(int i = 1; i <= n; i++){
 			pref[i] = pref[i - 1] + (s[i - 1] == '0');
 		}
 		if(pref[n] == n or pref[n] == 0){
 			cout << 0 << endl;
 			return 0;
 		}
 		auto ones = [&](int l,int r){
 			if(l > r)return 0LL;
 			return r - l + 1 - pref[r] + pref[l - 1];
 		};

 		int ans = n;
 		int l = 0, r = n;
 		while(l <= r){
 			int m = (l + r)/2;
 			bool found = (ones(1,n) <= m);

 			for(int i = 1; i <= n; i++){
 				auto itr = upper_bound(all(pref),pref[i - 1] + m) - pref.begin();
 				itr--;
 				if(ones(1,i - 1) + ones(itr + 1,n) <= m){
 					found = 1;
 					break;
 				}
 			}
 			if(found){
 				ans = m;
 				r = m - 1;
 			}else{
 				l = m + 1;
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