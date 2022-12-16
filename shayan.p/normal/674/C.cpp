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

const int maxn = 2e5 + 10;

int a[maxn];
ld dp[maxn], bf[maxn];
ld smt[maxn], sma[maxn], smi[maxn];

ld calc(int l, int r){
    return smt[r-1] - smt[l-1] - sma[l-1] * (smi[r-1] - smi[l-1]);
}

void go(int l, int r, int L, int R){
    if(r - l < 0)
	return;
    int mid = (l+r) >> 1;
    int st = max( mid, L );
    ld sm = sma[st-1] - sma[mid-1];
    ld nw = calc(mid, st);
    
    dp[mid] = 1e18;
    int bstp = -1;
    
    while(st <= R){
	sm += a[st];
	nw += ld(sm) / a[st];
	if(bstp == -1 || dp[mid] > nw + bf[st])
	    bstp = st, dp[mid] = nw + bf[st];
	st++;
    }

    if(r-l >= 1){
	go(l, mid-1, L, bstp);
	go(mid+1, r, bstp, R);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n,k;
    cin >> n >> k;

    for(int i = 1; i <= n; i++){
	cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
	sma[i] = sma[i-1] + a[i];
	smi[i] = smi[i-1] + (ld(1) / a[i]);
	smt[i] = smt[i-1] + (ld(sma[i]) / a[i]);
    }
    for(int i = 1; i <= n; i++){
	dp[i] = calc(i, n+1);
    }
    for(int _ = 2; _ <= k; _++){
	for(int i = 1; i <= n; i++){
	    bf[i] = dp[i+1];
	}
	go(1, n, 1, n);
    }
    return cout << setprecision(6) << fixed << dp[1] << endl, 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")