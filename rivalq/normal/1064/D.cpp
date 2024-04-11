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
 		int r,c; cin >> r >> c;
 		int x,y; cin >> x >> y;
 		vector<vector<char>>vec(n+1,vector<char>(m+1));
 		vector<vector<int>>dis(n+1,vector<int>(m+1,hell));
 		vector<vector<int>>vis(n+1,vector<int>(m+1));
 		rep(i,1,n+1){
 			rep(j,1,m+1){
 				cin >> vec[i][j];
 			}
 		}
 		multiset<pair<int,pii>>pq;
 		pq.insert({0,{r,c}});
 		dis[r][c] = 0;
 		auto add = [&](int x,int y,int c){
 			if(x <= 0 or x > n or y <= 0 or y > m)return;
 			if(vec[x][y] != '*' and dis[x][y] > c){
 				dis[x][y] = c;
 				pq.insert({c,{x,y}});
 			}
 		};

 		while(!pq.empty()){
 			auto s = *pq.begin();
 			pq.erase(s);
 			if(vis[s.y.x][s.y.y])continue;
 			vis[s.y.x][s.y.y] = 1;
 			int i = s.y.x;
 			int j = s.y.y;
 			int w = s.x;
 			add(i-1,j,w);
 			add(i+1,j,w);
 			add(i,j-1,w+1);
 			add(i,j+1,w);
 		}
 		int cnt = 0;
 		for(int i = 1; i <= n; i++){
 			for(int j = 1; j <= m; j++){
 				if(x >= dis[i][j]){
 					int k = dis[i][j] - c + j;
 					if(k <= y)cnt++;
 				}
 			}
 		}
 		cout << cnt << endl;
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