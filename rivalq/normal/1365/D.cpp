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
 	int n,m;cin>>n>>m;
 	vector<vector<char>>a(n+1,vector<char>(m+1));
 	int cnt=0;
 	rep(i,1,n+1){
 		rep(j,1,m+1){
 			cin>>a[i][j];
 			if(a[i][j]=='G')cnt++;
 		}
 	}
 	rep(i,1,n+1){
 		rep(j,1,m+1){
 			if(a[i][j]=='B'){
 				if(i-1>0){
 					if(a[i-1][j]=='G'){
 						cout<<"No"<<endl;return 0;
 					}
 					if(a[i-1][j]=='.')a[i-1][j]='#';
 				}
 				if(i+1<=n){
 					if(a[i+1][j]=='G'){
 						cout<<"No"<<endl;return 0;
 					}
 					if(a[i+1][j]=='.')a[i+1][j]='#';
 				}
 				if(j-1>0){
 					if(a[i][j-1]=='G'){
 						cout<<"No"<<endl;return 0;
 					}
 					if(a[i][j-1]=='.')a[i][j-1]='#';
 				}
 				if(j+1<=m){
 					if(a[i][j+1]=='G'){
 						cout<<"No"<<endl;return 0;
 					}
 					if(a[i][j+1]=='.')a[i][j+1]='#';
 				}
 			}
 		}
 	}
 	vector<pii>vec={{n,m}};
 	vector<vector<int>>vis(n+1,vector<int>(m+1));
 	vector<pii>dir={{1,0},{-1,0},{0,1},{0,-1}};
 	if(a[n][m]=='#'){
 		if(cnt==0){
 			cout<<"Yes"<<endl;
 		}
 		else{
 			cout<<"No"<<endl;
 		}
 		return 0;
 	}
 	for(int i=0;i<sz(vec);i++){
 		int x=vec[i].x,y=vec[i].y;
 		if(a[x][y]=='G')cnt--;
 		if(a[x][y]=='B'){
 			cout<<"No"<<endl;return 0;
 		}
 		vis[x][y]=1;
 		for(auto k:dir){
 			int nx=x+k.x,ny=y+k.y;
 			if(nx<=n && nx>0 && ny<=m && ny>0 && a[nx][ny]!='#' && !vis[nx][ny]){
 				vis[nx][ny]=1;
 				vec.push_back({nx,ny});
 			}
 		}
 	}
 	if(cnt==0)cout<<"Yes"<<endl;
 	else cout<<"No"<<endl;
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