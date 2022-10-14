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

const int N = 105;

int p;

int dp[N][N][N],c[N][N],fact[N];

int C(int n,int r){
	return c[n][r];
}


int rec(int n,int m,int k){
	if(n == 0)return k == 0;
	if(n == 1){
		if(m == 1 and  k == 1)return 1;
		if(k == 0 and  m > 1)return 1;
		return 0;
	}
	if(m == 0)return 0;
	if(m > n)return (k == 0)?fact[n]:0;

	if(dp[n][m][k] != -1)return dp[n][m][k];
	int &ans = dp[n][m][k];
	ans = 0;
	if(m == 1) {
		if(k == 1)return ans = fact[n];
		else return ans = 0;
	}
	__int128 temp = 0;
	for(int i = 0; i < n; i++){
	        __int128 val = 0;
		for(int j = 0; j <= k; j++){
		        val += rec(i,m - 1,j)*rec(n - 1 - i,m - 1,k - j); 
		}
	        temp += val*C(n - 1,i);
		temp %= p;
	}
	ans = temp;
	return ans;
}

int solve(){
 		int n,m,k; cin >> n >> m >> k >> p;
 		memset(dp,-1,sizeof(dp));

 		c[0][0] = 1;
 		for(int i = 1; i < N; i++){
 			c[i][0] = 1;
 			for(int j = 1; j <= i; j++){
 				c[i][j] = (c[i - 1][j] + c[i - 1][j - 1])%p;
 			}
 		}
 		fact[0] = 1;
 		for(int i = 1; i < N; i++){
 			fact[i] = 1LL*i*fact[i - 1]%p;
 		}
 		cout << rec(n,m,k) << endl;

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