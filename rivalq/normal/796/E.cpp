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


int dp[2][1005][52][52];

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int solve(){
 		int n,m,k; 
 		cin >> n >> m >> k;
 		vector<vector<int>>good(2,vector<int>(n + 1));
 		rep(j,0,2){
 			int k; cin >> k;
 			while(k--){
 				int x; cin >> x;
 				good[j][x] = 1;
 			}
 		}
 		
 		int can = 2*(n/k + (n % k != 0));
 		if(m >= can){
 			int ans = 0;
 			for(int i = 1; i <= n; i++){
 				ans += max(good[0][i],good[1][i]);
 			}
 			cout << ans << endl;
 			return 0;
 		}

 		int last = 0;
 		int curr = 1;
 		for(int i = 0; i <= m; i++){
 			for(int j = 0; j <= k; j++){
 				for(int l = 0; l <= k; l++)dp[0][i][j][l] = dp[1][i][j][l] = INT_MIN;
 			}
 		}
 		dp[last][0][0][0] = 0;
 		vector<int> pos_states_1 = {0,0};
 		vector<int> pos_states_2 = {0,0};
 		for(int i = 1; i <= n; i++){
 			for(int p = 0; p <= m; p++){
 				for(int j = 0; j <= k; j++){
 					for(int l = 0; l <= k; l++){
 						dp[curr][p][j][l] = INT_MIN;
 						int reqd = (j == 1) + (l == 1);
 						if(reqd > p)continue;
 						pos_states_1[0] = pos_states_1[1] = j - 1;
 						pos_states_2[0] = pos_states_2[1] = l - 1;
 
						if(j <= 1){
						    pos_states_1[0] = 0;
						    pos_states_1[1] = k;
						}
						if(l <= 1){
						    pos_states_2[0] = 0;
						    pos_states_2[1] = k;
						}
						
						for(auto s1:pos_states_1){
							for(auto s2:pos_states_2){
								maxs(dp[curr][p][j][l],dp[last][p - reqd][s1][s2]);
							}
						}
						int val = 0;
						if(j > 0) val |= good[0][i];
						if(l > 0 and val == 0) val |= good[1][i];
						dp[curr][p][j][l] += val;
 					}
 				}
 			}
 			swap(last,curr);
 		}
 		int ans = 0;
 		for(int p = 0; p <= m; p++){
 			for(int i = 0; i <= k; i++){
	 			for(int j = 0; j <= k; j++){
	 				maxs(ans,dp[last][p][i][j]);
	 			}
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