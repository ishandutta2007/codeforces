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


int solve(){
 		int n; cin >> n;
 		bitset<512> dp;
 		dp[0] = 1;
 		vector<bitset<512>> bs(512);
 		bs[0][0] = 1;
 		for(int i = 1; i <= n; i++){
 			int x; cin >> x;
 			//int x = rng()%501;
 			bitset<512> pos;
 			for(int j = 0; j < x; j++){
 				pos |= bs[j];
 			}
 			for(int j = 0; j < 512; j++){
 				if(pos[j]){
 					bs[x][j^x] = 1;
 				}
 			}
 			dp |= bs[x];
 		}
 		vector<int> ans;
 		for(int i = 0; i < 512; i++){
 			if(dp[i]){
 				ans.push_back(i);
 			}
 		}
 		cout << ans.size() << endl;
 		for(auto i:ans)cout << i << " ";cout << endl;

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