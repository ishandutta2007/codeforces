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

const int N = 155;
bool dp[305][305][31][6][3][3];

int solve(){
 		int n; cin >> n;
 		vector<int> a(n);
 		for(auto &i:a){
 			cin >> i;
 		}
 		set<pii>st;


 		function<void(int,int,int,int,int,int)>dfs = [&](int i,int j,int level,int t,int dx,int dy){
 			if(dp[i][j][level][t][dx + 1][dy + 1])return;
 			dp[i][j][level][t][dx + 1][dy + 1] = 1;
 			st.insert({i,j});
 			if(t == 0){
 				if(level == n - 1)return;
 				pii p1,p2;
 				if(dx == 1 and dy == 0){
 					p1 = {1,1};
 					p2 = {1,-1};
 				}else if(dx == 1 and dy == 1){
 					p1 = {1,0};
 					p2 = {0,1};
 				}else if(dx == 1 and dy == -1){
 					p1 = {1,0};
 					p2 = {0,-1};
 				}else if(dx == 0 and dy == 1){
 					p1 = {1,1};
 					p2 = {-1,1};
 				}else if(dx == 0 and dy == -1){
 					p1 = {-1,-1};
 					p2 = {1,-1};
 				}else if(dx == -1 and dy == -1){
 					p1 = {-1,0};
 					p2 = {0,-1};
 				}else if(dx == -1 and dy == 0){
 					p1 = {-1,1};
 					p2 = {-1,-1};
 				}else {
 					assert(dx == -1 and dy == 1);
 					p1 = {0,1};
 					p2 = {-1,0};
 				}
 				dfs(i,j,level + 1,a[level + 1],p1.x,p1.y);
 				dfs(i,j,level + 1,a[level + 1],p2.x,p2.y);
 			}else{
 				dfs(i + dx,j + dy,level,t - 1,dx,dy);
 			}
 		};
 		dfs(151,151,0,a[0] - 1,0,1);
 		cout << sz(st) << endl;
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