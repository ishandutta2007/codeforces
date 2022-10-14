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
 		int n,m,w; cin >> n >> m >> w;
 		vector<vector<int>>a(n+1,vector<int>(m+1));
 		rep(i,1,n+1){
 			rep(j,1,m+1){
 				cin >> a[i][j];
 			}
 		}
 		vector<pii> c = {{-1,0},{1,0},{0,-1},{0,1}}; 
 		auto bfs = [&](pii s){
 			vector<vector<int>>d(n+1,vector<int>(m+1,hell));
 			vector<vector<int>>vis(n+1,vector<int>(m+1,0));
 			d[s.x][s.y] = 0;
 			vector<pii> v = {s};
 			for(int i = 0; i < v.size(); i++){
 				auto u = v[i];
 				vis[u.x][u.y] = 1;
 				for(int k = 0; k < 4; k++){
 					int dx = u.x + c[k].x;
 					int dy = u.y + c[k].y;
 					if(dx <= 0 or dx > n or dy <= 0 or dy > m)continue;
 					if(!vis[dx][dy] and a[dx][dy] != -1){
 						v.push_back({dx,dy});
 						vis[dx][dy] = 1;
 						d[dx][dy] = d[u.x][u.y] + 1;
 					}
 				}
 			}
 			return d;
 		};
 		vector<vector<int>>d1 = bfs({1,1});
 		vector<vector<int>>d2 = bfs({n,m});
 		int ans;
 		if(d1[n][m] == hell){
 			ans = 1e18;
 		}
 		else{
 			ans = d1[n][m]*w;
 		}
		int mn1 = 1e18;
		int mn2 = 1e18;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(a[i][j] > 0){
					if(d1[i][j] != hell)mins(mn1, d1[i][j]*w + a[i][j]);
					if(d2[i][j] != hell)mins(mn2, d2[i][j]*w + a[i][j]);	
				}
				
			}
		} 		
		mins(ans,mn1 + mn2);
		if(ans == 1e18)ans = -1;
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