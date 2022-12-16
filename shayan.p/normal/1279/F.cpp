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
typedef long double ld;

const int maxn = 1e6 + 10;
const ll inf = 1e18;

int n, k, l;
bool a[maxn];
ll dp[maxn];
int dpc[maxn];

int solve(){
    int L = 0, R = maxn;
    while( R - L > 1 ){
	int mid = (L + R) /2;

	dp[0] = 0;
	
	for(int i = 1; i <= n; i++){
	    ll A = dp[i-1] + a[i-1];
	    ll B = (i >= l) ? (dp[i-l] + mid) : (inf);
	    if( A < B )
		dp[i] = A, dpc[i] = dpc[i-1];
	    else if( A > B )
		dp[i] = B, dpc[i] = dpc[i-l] + 1;
	    else
		dp[i] = A, dpc[i] = max( dpc[i-1], dpc[i-l] + 1 );
	}
	if( dpc[n] < k )
	    R = mid;
	else
	    L = mid;
    }

    if( L == 0 )
	return 0;    
    for(int i = 1; i <= n; i++){
	ll A = dp[i-1] + a[i-1];
	ll B = i >= l ? dp[i-l] + L : inf;
	dp[i] = min( A, B );
    }
    return dp[n] - 1ll * k * L;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    cin >> n >> k >> l;
    
    string s;
    cin >> s;
    for(int i = 0; i < n; i++){
	a[i] = 'a'<=s[i] && s[i]<='z';
    }
    int ans = solve();
    for(int i = 0; i < n; i++){
	a[i]^=1;
    }
    ans = min( ans, solve() );
    return cout << ans << endl, 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")