// Never let them see you bleed...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;

const int maxn = 3e5 + 10, mod = 998244353, inf = 1e9 + 10;

int dp[maxn], a[maxn];
pii DP[maxn];

pii operator * (pii a, int b){
    return {1ll * a.F * b % mod, 1ll * a.S * b % mod};    
}
pii operator - (pii a, pii b){
    return {(a.F - b.F) % mod, (a.S - b.S) % mod};
}
pii operator + (pii a, pii b){
    return {(a.F + b.F) % mod, (a.S + b.S) % mod};
}

int Pow(int a, int b){
    int ans = 1;
    for(; b; b>>=1, a = 1ll * a * a % mod)
	if(b&1)
	    ans = 1ll * ans * a % mod;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n, sm = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
	cin >> a[i];
	sm+= a[i];
    }
    DP[sm] = {0,0};
    DP[sm-1] = {1, 0};
    int _minus = Pow(sm, mod-2);
    int _plus = Pow(n-1, mod-2);
    for(int i = sm-1; i > 0 ; i--){
	int minus = 1ll * i * _minus % mod;
	int plus = 1ll * (1-minus) * _plus % mod;
	int self = 1ll * (1-minus) * (n-2) % mod * _plus % mod;
	DP[i-1] = (DP[i] - DP[i] * self - DP[i+1] * plus - (pii){0, 1}) * Pow(minus, mod-2);
    }
    int plus = _plus;
    int self = 1ll * (n-2) * _plus % mod;
    pii p = (pii){0, 1} + DP[1] * plus + DP[0] * self;
    int x = 1ll * (p.S - DP[0].S) * Pow(DP[0].F - p.F, mod-2) % mod;
    for(int i = 0; i < sm; i++){
	dp[i] = (1ll * DP[i].F * x + 1ll * DP[i].S) % mod;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
	ans = (ans + dp[a[i]]) % mod;
    }
    ans = (1ll * ans - 1ll * (n-1) * dp[0]) % mod;
    ans = 1ll * ans * Pow(n, mod-2) % mod;
    if(ans < 0)
	ans+= mod;
    return cout << ans << endl, 0;
}