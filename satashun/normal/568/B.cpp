#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

const ll MOD = 1000000007;

ll dp[4010];
ll comb[4010][4010];
int n;

int main() {
    for (int i = 0; i <= 4000; ++i) {
	comb[i][0] = comb[i][i] = 1;
	for (int j = 1; j < i; ++j) {
	    comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % MOD;
	}
    }

    cin >> n;

    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
	for (int j = 1; j <= i; ++j) {
	    dp[i] = (dp[i] + dp[i-j] * comb[i-1][j-1]) % MOD;
	}
    }

    ll ret = 0;

    for (int i = 1; i <= n; ++i) {
	ret = (ret + comb[n][i] * dp[n-i]) % MOD;
    }

    cout << ret << endl;

    return 0;
}