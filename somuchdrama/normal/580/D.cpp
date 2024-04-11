#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define sqr(x) ((x) * (x))

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 18;

bool bit(int x, int i) {
    return x & (1 << i);
}

int setbit1(int x, int i) {
    return (x |= (1 << i));
}

int setbit0(int x, int i) {
    return (x &= ~(1 << i));
}

int bitcnt(int x, int n) {
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        if (bit(x, i))
            ++cnt;
    return cnt;
}

ll dp[1 << MAXN][MAXN];
vector<pll> pl[MAXN];
ll arr[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cout << fixed;
    cout.precision(10);
    cerr << fixed;
    cerr.precision(10);
    
    int n, m, k;
    cin >> n >> m >> k;

    for (unsigned int i = 0; i < (1 << n); ++i)
    	for (int j = 0; j < n; ++j)
    		dp[i][j] = 0;

    for (int i = 0; i < n; ++i)
    	cin >> arr[i];

    for (int i = 0; i < k; ++i) {
    	int a, b; ll c;
    	cin >> a >> b >> c;
    	pl[a - 1].pb({b - 1, c});
    }

    for (int i = 0; i < n; ++i)
    	dp[setbit1(0, i)][i] = arr[i];

    for (unsigned int i = 0; i < (1 << n); ++i) {
    	for (int j = 0; j < n; ++j) {
    		if (!bit(i, j))
    			continue;
    		for (int k = 0; k < n; ++k) {
    			if (bit(i, k))
    				continue;
    			dp[setbit1(i, k)][k] = max(dp[setbit1(i, k)][k], dp[i][j] + arr[k]);
    		}
    		for (auto k : pl[j]) {
    			if (bit(i, k.ff))
    				continue;
    			dp[setbit1(i, k.ff)][k.ff] = max(dp[setbit1(i, k.ff)][k.ff], dp[i][j] + arr[k.ff] + k.ss);
    		}
    	}
    }
    ll ans = 0;
    for (unsigned int i = 0; i < (1 << n); ++i) {
    	for (int j = 0; j < n; ++j) {
    		if (bitcnt(i, n) == m) {
    			ans = max(ans, dp[i][j]);
    		}
    	}
    }
    cout << ans << '\n';

    return 0;
}