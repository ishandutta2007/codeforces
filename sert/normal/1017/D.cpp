#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)4.1e3;
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
const int M = 102;

int num[N];
int w[N];
int dp[N][M];

int get10(string s) {
    int val = 0;
    for (int i = 0; i < (int)s.length(); i++) {
        if (s[i] == '1') val += (1 << i);
    }
    return val;
}

void solve() {
    int q, m, x, n;
    char ss[15];
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < n; i++) {
        scanf("%d", w + i);
    }

    for (int i = 0; i < m; i++) {
        scanf("%s", ss);
        num[get10(ss)]++;
        //cerr << get10(ss) << "\n";
    }

    for (int msk1 = 0; msk1 < (1 << n); msk1++) {
        for (int msk2 = 0; msk2 < (1 << n); msk2++) {
            int x = 0;
            for (int i = 0; i < n; i++) {
                if ((msk1 & (1 << i)) == (msk2 & (1 << i))) {
                    x += w[i];
                }
            }
            if (x >= M) continue;

            //if (msk2 == 0)
            //    cerr << msk1 << " " << msk2 << " " << x << "\n";

            dp[msk2][x] += num[msk1];
        }
    }

    for (int msk = 0; msk < (1 << n); msk++) {
        for (int i = 1; i < M; i++) {
            dp[msk][i] += dp[msk][i - 1];
        }
    }

    while (q--) {
        scanf("%s %d", ss, &x);
        int val = get10(ss);

        printf("%d\n", dp[val][x]);
    }
}

int main() {
#ifdef MADE_BY_SERT
	freopen("a.in", "r", stdin);
	//solve();
#endif

	//int t; scanf("%d", &t); while (t--)
	//int t; cin >> t; while (t--)
	solve();
}