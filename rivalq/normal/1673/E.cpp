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


 		vector<int>a(n);
 		for(auto &i:a)cin >> i;

 		auto is_odd = [&](int n,int r){
 			if(r < 0 || r > n)return false;
 			return (n & r) == r; 
 		};
 		vector<int> ans(1 << 20,0);
 		vector<vector<int>>dp(30,vector<int>(3));
 		for(int i = 0; i < 30; i++){
 			for(int l = 0; l <= 2; l++){
 				//dp[i] = C(n - i,n) + C(n - i,n - 1)..... C(n - i,k - 2)
	 			for(int j = n - 1 - i; j >= max(0LL,k - l); j--){
	 				dp[i][l] ^= is_odd(n - 1 - i,j);
	 			}
 			}
 			
 		}


 		for(int i = 0; i < n; i++){
 			int val = a[i];
 			int cnt = (i > 0);
 			int temp = n - 1;
 			int restricted = 0;
 			for(int end = i; end < n; end++){
 				if(end > i){
 					if(a[end] <= 20){
 						 val *= (1LL << a[end]);
 					}else{
 						break;
 					}
 				}
 				if(val >= (1 << 20))break;

 				if(temp < k)break;
 				int t = cnt + (end + 1 < n);
 				int rem = temp - t;
 				restricted = (n - 1 - temp) + t;

 				

 				if(dp[restricted][t]){
 					//cout << restricted << " " << val << endl;
 					ans[val] ^= 1;
 				}
 				temp--;			
 			}
 		}

 		

 		while(ans.size() > 0 and ans.back() == 0)ans.pop_back();
 		reverse(all(ans));
 		if(ans.size() == 0)ans.push_back(0);
 		for(auto i:ans)cout << i;
 		cout << endl;


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