// Jai Shree Ram  
  
#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define ll             long long
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
 		vector<int> a(n);
 		for(int i = 0; i < n; i++){
 			char c; cin >> c;
 			if(c == '?')a[i] = -1;
 			else a[i] = c - 97;
 		}
 		auto check = [&](int x){
 			vector<pii> vec[k];
 			map<int,int>mp;
 			for(int i = 0; i < x; i++){
 				if(a[i] == -1)continue;
 				mp[a[i]]++;
 			}
 			if(mp.size() <= 1){
 				if(mp.size() == 1){
 					//cout << x << endl;
 					auto itr = mp.begin()->x;
 					vec[itr].push_back({0,x - 1});
 				}else{
 					for(int j = 0; j < k;j++){
 						vec[j].push_back({0,x - 1});
 					}
 				}
 			}
 			for(int i = x; i < n; i++){
 				if(a[i - x] >= 0){
 					mp[a[i - x]]--;
 					if(mp[a[i - x]] == 0){
 						mp.erase(a[i - x]);
 					}
 				}
 				if(a[i] >= 0){
 					mp[a[i]]++;
 				}
 				if(mp.size() <= 1){
	 				if(mp.size() == 1){
	 					auto itr = mp.begin()->x;
	 					vec[itr].push_back({i - x + 1, i});
	 				}else{
	 					for(int j = 0; j < k;j++){
	 						vec[j].push_back({i - x + 1,i});
	 					}
	 				}
	 			}
 			}
 			for(int i = 0; i < k; i++){
 				if(vec[i].empty())return false;
 			}
 			vector<int>dp(1 << k,n + 1);
 			dp[0] = -1;
 			for(int mask = 0; mask < (1 << k);mask++){
 				for(int j = 0; j < k; j++){
 					if(((1 << j)&mask) == 0){
 						if(vec[j].back().x > dp[mask]){
 							int idx = upper_bound(all(vec[j]),make_pair(dp[mask],n)) - vec[j].begin();
 							mins(dp[mask + (1 << j)],vec[j][idx].y);
 						}
 					}
 				}
 			}
 			return dp.back() <= n;
 		};
 		int ans = 0;
 		int l = 1,r = n;
 		while(l <= r){
 			int m = (l + r)/2;
 			if(check(m)){
 				ans = m;
 				l = m + 1;
 			}else{
 				r = m - 1;
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
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}