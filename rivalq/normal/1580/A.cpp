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

const int N = 4e3 + 5;


int solve(){
 
		int n,m; cin >> n >> m;

		vector<vector<int>> mat(n + 1,vector<int>(m + 1));
		vector<vector<int>> zero(n + 1,vector<int>(m + 1));
		vector<vector<int>> ones(n + 1,vector<int>(m + 1));

		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				char c; cin >> c;
				mat[i][j] = c - '0';
				zero[i][j] = zero[i][j - 1] + (mat[i][j] == 0);
				ones[i][j] = ones[i][j - 1] + (mat[i][j] == 1);
				
			}
		}	
		auto query_0 = [&](int row,int i,int j){
			return zero[row][i] - zero[row][j - 1];
		};

		auto query_1 = [&](int row,int i,int j){
			return ones[row][i] - ones[row][j - 1];
		};

		int ans = n*m;
		for(int len = 4; len <= m; len++){
			for(int i = 1, j = len; j <= m; i++,j++){
				vector<int>middle(n + 1);
				vector<int>side(n + 1);
				for(int row = 1; row <= n; row++){
					// 100001
					middle[row] = (mat[row][i] == 0) + (mat[row][j] == 0) + (query_1(row,j - 1, i + 1));
					middle[row] += middle[row - 1];	
					// ?1111?
					side[row] = query_0(row,j - 1, i + 1); 
				}
				int mn = n*m;

				for(int l = 1, row = 5; row <= n; row++,l++){
					mn = min(mn,side[l] - middle[l]);
					mins(ans,mn + side[row] + middle[row - 1]); 	
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
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}