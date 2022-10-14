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
 		int n; cin >> n;
 		vector<vector<char>>a(n+1,vector<char>(n+1));
 		vector<pii>vec;
 		for(int i = 1; i <= n; i++){
 			for(int j = 1; j <= n; j++){
 				cin >> a[i][j];
 				if(a[i][j] == '*'){
 					vec.push_back({i,j});
 				}
 			}
 		}
 		if(vec[0].x == vec[1].x){
 			int x = vec[0].x;
 			int y1 = vec[0].y;
 			int y2 = vec[1].y;
 			if(x - 1 > 0){
 				a[x-1][y1]=a[x-1][y2]='*';
 			}
 			else{
 				a[x+1][y1]=a[x+1][y2]='*';
 			}
 		}	
 		else if(vec[0].y == vec[1].y){
 			int y = vec[0].y;
 			int x1 = vec[0].x;
 			int x2 = vec[1].x;
 			if(y - 1 > 0){
 				a[x1][y-1]=a[x2][y-1]='*';
 			}
 			else{
 				a[x1][y+1]=a[x2][y+1]='*';
 			}
 		}
 		else{
 			int x1 = vec[0].x;
 			int x2 = vec[1].x;
 			int y1 = vec[0].y;
 			int y2 = vec[1].y;
 			a[x1][y2] = a[x2][y1] = '*';
 		}	
 		for(int i = 1; i <= n; i++){
 			for(int j = 1; j <= n; j++){
 				cout << a[i][j];
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