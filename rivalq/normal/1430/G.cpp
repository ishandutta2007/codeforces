#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define eb             emplace_back
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC
using namespace std;


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}


#define double 	long double

const double EPS = 1e-9;
 
typedef vector<double>  T;

struct simplex {
  int m, n;
  vector<int> B, N;
  vector<T> D;
  	  // everything is 0-based,variables starts from x0,x1...xn-1
   	  // m equations e0,e1,e2...em	
  	  // equality included 	
          // A-> coefficent matrix on left hand side
          // B-> right hande side of inequality	
          // AX<=B 
          // maximize CX	
  simplex(const vector<T> &A, const T &b, const T &c) :
	    m(b.size()), n(c.size()), N(n + 1), B(m), D(m + 2, T(n + 2)) {
	    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) D[i][j] = A[i][j];
	    for (int i = 0; i < m; i++) { B[i] = n + i; D[i][n] = -1; D[i][n + 1] = b[i]; }
	    for (int j = 0; j < n; j++) { N[j] = j; D[m][j] = -c[j]; }
	    N[n] = -1; D[m + 1][n] = 1;
  }
 
  void Pivot(int r, int s) {
	    double inv = 1.0 / D[r][s];
	    for (int i = 0; i < m + 2; i++) if (i != r)
	           for (int j = 0; j < n + 2; j++) if (j != s)
	           D[i][j] -= D[r][j] * D[i][s] * inv;
	    for (int j = 0; j < n + 2; j++) if (j != s) D[r][j] *= inv;
	    for (int i = 0; i < m + 2; i++) if (i != r) D[i][s] *= -inv;
	    D[r][s] = inv;
	    swap(B[r], N[s]);
  }
 
  bool Simplex(int phase) {
	    int x = phase == 1 ? m + 1 : m;
	    while (true) {
	      int s = -1;
	      for (int j = 0; j <= n; j++) {
	        	if (phase == 2 && N[j] == -1) continue;
	        	if (s == -1 || D[x][j] < D[x][s] || D[x][j] == D[x][s] && N[j] < N[s]) s = j;
	      }
	      if (D[x][s] > -EPS) return true;
	      int r = -1;
	      for (int i = 0; i < m; i++) {
	        	if (D[i][s] < EPS) continue;
	        	if (r == -1 || D[i][n + 1] / D[i][s] < D[r][n + 1] / D[r][s] || (D[i][n + 1] / D[i][s]) == (D[r][n + 1] / D[r][s]) && B[i] < B[r]) r = i;
	      }
	      if (r == -1) return false;
	      Pivot(r, s);
	    }
	  }
 
  double Solve(T &x) {
	    int r = 0;
	    for (int i = 1; i < m; i++) if (D[i][n + 1] < D[r][n + 1]) r = i;
	    if (D[r][n + 1] < -EPS) {
	      	Pivot(r, n);
	      	if (!Simplex(1) || D[m + 1][n + 1] < -EPS) return -numeric_limits<double>::infinity();
	      	for (int i = 0; i < m; i++) if (B[i] == -1) {
	        	int s = -1;
	        	for (int j = 0; j <= n; j++){
	         		if (s == -1 || D[i][j] < D[i][s] || D[i][j] == D[i][s] && N[j] < N[s]) s = j;
	        		Pivot(i, s);
	        	}	
	      	}	
	    }
	    if (!Simplex(2)) return numeric_limits<double>::infinity();
	    x = T(n);
	    for (int i = 0; i < m; i++) if (B[i] < n) x[B[i]] = D[i][n + 1];
	    return D[m][n + 1];
  }
};


int solve(){
 		int n,m;cin>>n>>m;
 		vector<double>b(m,-1);
 		vector<double>c(n);
 		vector<vector<double>>a(m,vector<double>(n,0));
 		rep(i,0,m){
 			int u,v,w;cin>>u>>v>>w;
 			u--;v--;
 			c[u]-=w;
 			c[v]+=w;
 			a[i][u]=-1;
 			a[i][v]=1;
 		}
 		// lhs,rhs,cost
 		simplex solver(a,b,c);
 		vector<double>res;
 		solver.Solve(res);
 		vector<int>ans(n);
 		int mn=1e18;
 		rep(i,0,n){
 			ans[i]=(int)(res[i]+0.5);
 			mins(mn,ans[i]);
 		}
 		rep(i,0,n){
 			cout<<ans[i]-mn<<" ";
 		}cout<<endl;
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