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

const int N = 505;


int dp[N][N][20];
int vis[N][N][20];

int r[N][N];
int down[N][N];
int up[N][N];
int l[N][N];

int n,m;

int zeno(int i,int j,int k){
	if(vis[i][j][k]){
		return dp[i][j][k];
	}
	vis[i][j][k] = 1;
	if(k == 0){
		return dp[i][j][k] = 0;
	}
	int &ans = dp[i][j][k];
	ans = 1LL << 60;
	if(i - 1 > 0){
		mins(ans,zeno(i-1,j,k-1) + 2*up[i][j]);
	}
	if(j - 1 > 0){
		mins(ans,zeno(i,j-1,k-1) + 2*l[i][j]);
	}
	if(i + 1 <= n){
		mins(ans,zeno(i+1,j,k-1) + 2*down[i][j]);
	}
	if(j + 1 <= m){
		mins(ans,zeno(i,j+1,k-1) + 2*r[i][j]);
	}
	return ans;
}


int solve(){
 		cin >> n >> m;
 		int k; cin >> k; 
 		rep(i,1,n+1){
 			for(int j = 1; j < m; j++){
 				int t; cin >> t;
 				r[i][j] = l[i][j+1] = t;
 			}
 		}
 		rep(i,1,n){
 			for(int j = 1; j <= m; j++){
 				int t; cin >> t;
 				down[i][j] = up[i+1][j] = t;
  			}
 		}
 		if(k%2){
 			for(int i = 1; i <= n; i++){
 				for(int j =1; j <= m; j++){
 					cout << -1 << " ";
 				}
 				cout << endl;
 			}
 		}
 		else{
 			for(int i = 1; i <= n; i++){
 				for(int j = 1; j <= m; j++){
 					cout << zeno(i,j,k/2) << " ";
 				}
 				cout << endl;
 			}
 		}
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