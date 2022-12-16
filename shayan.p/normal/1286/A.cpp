// They can't break me, as long as I know who I am...

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

const int maxn = 110, mod = 1e9 + 7, inf = 1e9;

int dp[maxn][maxn][2];
int a[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n; cin>>n;
    int A=0, B=0;
    for(int i = 0; i < n; i++){
	cin >> a[i];
	if(a[i] != 0)
	    (a[i] & 1 ? A : B)++;
    }
    for(int i = 0; i <= n; i++)
	for(int j = 0; j <= n; j++)
	    dp[i][j][0] = dp[i][j][1] = inf;
    
    dp[0][0][0] = 0;
    dp[0][0][1] = 0;
    
    int cnt = 0;
    for(int i = 0; i < n; i++){
	cnt+= a[i] == 0;
	for(int j = 0; j < n; j++){
	    int o = a[i] &1;
	    if(a[i] == 0){
		for(int k = 0; k < 2; k++)
		    dp[i+1][j + k][k] = min( dp[i+1][j + k][k], min( dp[i][j][k], dp[i][j][k ^ 1] + 1 ) );
	    }
	    else{
		dp[i+1][j][o] = min( dp[i+1][j][o], min( dp[i][j][o], dp[i][j][o ^ 1] + 1 ) );
	    }
	}
    }
    A = ((n+1)/2) - A;
    return cout << min( dp[n][A][0], dp[n][A][1] ) <<"\n",0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")