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
 		int n,m; cin >> n >> m;
 		vector<vector<char>> vec(n + 1,vector<char>(m + 1));
 		pii p;
 		for(int i = 1; i <= n; i++){
 			for(int j = 1; j <= m; j++){
 				cin >> vec[i][j];
 				if(vec[i][j] == 'L')p = {i,j};
 			}
 		}
 		vector<vector<int>> vis(n + 1,vector<int>(m + 1));
 		vector<vector<int>> can(n + 1,vector<int>(m + 1));
 		can[p.x][p.y] = 1;
 		queue<pii> q; q.push(p);
 		vector<int> dx = {0,0,-1,1};
 		vector<int> dy = {1,-1,0,0};

 		auto good = [&](int x,int y){
 			if(vec[x][y] == '#')return false;
 			int cnt = 0;
 			for(int k = 0; k < 4; k++){
 				int i = x + dx[k];
 				int j = y + dy[k];
 				if(i >= 1 and j >= 1 and i <= n and j <= m){
 					if(!can[i][j] and vec[i][j] == '.'){
 						cnt++;
 					}
 				}
 			}
 			return cnt <= 1;
 		};
 		vis[p.x][p.y] = 1;
 		while(!q.empty()){
 			int x = q.front().x;
 			int y = q.front().y;
 			q.pop();
 			for(int k = 0; k < 4; k++){
 				int i = x + dx[k];
 				int j = y + dy[k];
 				if(i >= 1 and j >= 1 and i <= n and j <= m){
 					if(!vis[i][j] and good(i,j)){
 						vis[i][j] = 1;
 						can[i][j] = 1;
 						q.push({i,j});
 					}
 				}
 			}
 		}
 		for(int i = 1; i <= n; i++){
 			for(int j = 1; j <= m; j++){
 				if(vec[i][j] == '.' and can[i][j])vec[i][j] = '+';
 				cout << vec[i][j]; 
 			}
 			cout << endl;
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
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}