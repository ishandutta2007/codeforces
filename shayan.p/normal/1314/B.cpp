// So when you feel like hope is gone, Look inside you and be strong, And you'll finally see the truth, That a hero lies in you ... 
 
#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn = 2e5 + 10, mod = 1e9 + 7, inf = 1e9;

template<typename A, typename B> ostream& operator << (ostream& out, pair<A, B> p){
    out << "{ " << p.F << ", " << p.S <<" }";
    return out;
}
template<typename T> ostream& operator << (ostream& out, vector<T> v){
    out << "[ ";
    for(int i = 0; i < sz(v); i++){
	out << v[i];
	if(i != sz(v)-1)
	    out << " ,";
    }
    out << " ]";
    return out;
}

int dp[maxn][4], dp2[maxn][4];
bool is[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n, k;
    cin >> n >> k;
    for(int i = 0; i < k; i++){
	int x;
	cin >> x;
	is[--x] = 1;
    }
    int N = 1<<n;
    for(int i = 0; i < N; i+=2){
	for(int j = 0; j < 4; j++)
	    dp[i/2][j] = -inf;
	dp[i/2][ (2*is[i]) + is[i+1] ] = is[i] || is[i+1];
	dp[i/2][ (2*is[i+1]) + is[i] ] = is[i] || is[i+1];	
    }
    N>>=1;
    
    while(N > 1){
	for(int i = 0; i < N; i++)
	    for(int j = 0; j < 4; j++)
		dp2[i][j] = dp[i][j];
	for(int i = 0; i < N; i+=2){
	    for(int j = 0; j < 4; j++)
		dp[i/2][j] = -inf; 
	    for(int j = 0; j < 4; j++){
		for(int w = 0; w < 4; w++){
		    for(int who1 : {0, 1}){ // winner
			for(int who2 : {0, 1}){
			    for(int who3 : {0, 1}){
				int num = dp2[i][j] + dp2[i+1][w] + (bit(j, 0) || bit(w, 0)) + (bit(j, 1) || bit(w, 1)) + (bit(who1 ? j : w, 0) || bit(who2 ? w : j, 1));
				bool A = bit(who1 ? j : w, 0), B = bit(who2 ? w : j, 1);
				int msk = (bit(who1 ? w : j, 0)) + 2 * (who3 ? B : A);
				dp[i/2][msk] = max( dp[i/2][msk], num );
			    }
			}
		    }
		}
	    }
	}
	N>>=1;
    }
    return cout << max({dp[0][0], dp[0][1] + 1, dp[0][2] + 1, dp[0][3] + 1}) << endl, 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")