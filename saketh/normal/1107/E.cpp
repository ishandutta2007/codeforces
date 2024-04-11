#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll dp[101][101][101][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    string str;
    cin >> str;

    vi a(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> a[i];

    for (int len = 0; len <= N; len++) {
        for (int inx = 0; inx + len <= N; inx++) {
            for (int grp = N; grp >= 0; grp--) {
                for (int val = 0; val < 2; val++) {
                    ll& res = dp[len][inx][grp][val];
                    for (int fst = inx; fst < inx + len; fst++) {
                        if ((str[fst] - '0') == val || grp == 0) {
                            res = max(res, dp[fst - inx][inx][0][0] +
                                    dp[len - (fst - inx) - 1][fst + 1][grp + 1][str[fst] - '0']);
                        }
                    }
                    if (grp) {
                        ll pos = a[grp];
                        if (len) {
                            pos += dp[len-1][inx+1][1][str[inx]-'0'];
                        }
                        res = max(res, pos);
                    }
                }
            }
        }
    }

    cout << dp[N][0][0][0] << endl;

    return 0;
}