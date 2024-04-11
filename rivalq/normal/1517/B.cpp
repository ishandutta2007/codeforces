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
 		vector<vector<int>>a(n+1,vector<int>(m));
 		vector<int>L(n+1,0);
 		vector<int>R(n+1,m-1);
 		rep(i,1,n+1){
 			rep(j,0,m){
 				cin >> a[i][j];
 			}
 			sort(a[i].begin(),a[i].end());
 		}

 		vector<vector<int>>ans(n+1,vector<int>(m));

		for(int j = 0; j < m; j++){
			pii mi = {hell,hell};
			for(int i = 1; i <= n; i++){
				mins(mi,make_pair(a[i][L[i]],i));
			}

			for(int i = 1; i <= n; i++){
				if(mi.y != i){
					ans[i][j] = a[i][R[i]--];
				}
				else{
					ans[i][j] = a[i][L[i]++];
				}
			}

		} 	
		for(int i = 1; i <= n; i++){
			for(auto j:ans[i])cout << j << " ";
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