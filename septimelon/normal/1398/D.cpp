#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 998244353;

ll sum(ll a, ll b) {
    ll ans = a + b;
    while (ans > MOD) {
        ans -= MOD;
    }
    return ans;
}

ll mul(ll a, ll b) {
    return (a * b) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int sr, sg, sb;
    cin >> sr >> sg >> sb;
    vector<int> r(sr), g(sg), b(sb);
    for (int i = 0; i < sr; ++i) {
        cin >> r[i];
    }
    for (int i = 0; i < sg; ++i) {
        cin >> g[i];
    }
    for (int i = 0; i < sb; ++i) {
        cin >> b[i];
    }
    sort(r.begin(), r.end());
    reverse(r.begin(), r.end());
    sort(g.begin(), g.end());
    reverse(g.begin(), g.end());
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());

    vector<vector<vector<int>>> maxa(sr + 1, vector<vector<int>>(sg + 1, vector<int>(sb + 1, 0)));
    for (int ir = 0; ir <= sr; ++ir) {
        for (int ig = 0; ig <= sg; ++ig) {
            for (int ib = 0; ib <= sb; ++ib) {
                if (ir < sr) {
                    maxa[ir + 1][ig][ib] = max(maxa[ir + 1][ig][ib], maxa[ir][ig][ib]);
                    if (ig < sg) {
                        maxa[ir + 1][ig + 1][ib] = max(maxa[ir + 1][ig + 1][ib], maxa[ir][ig][ib] + r[ir] * g[ig]);
                    }
                    if (ib < sb) {
                        maxa[ir + 1][ig][ib + 1] = max(maxa[ir + 1][ig][ib + 1], maxa[ir][ig][ib] + r[ir] * b[ib]);
                    }
                }
                if (ig < sg) {
                    maxa[ir][ig + 1][ib] = max(maxa[ir][ig + 1][ib], maxa[ir][ig][ib]);
                    if (ib < sb) {
                        maxa[ir][ig + 1][ib + 1] = max(maxa[ir][ig + 1][ib + 1], maxa[ir][ig][ib] + g[ig] * b[ib]);
                    }
                }
                if (ib < sb) {
                    maxa[ir][ig][ib + 1] = max(maxa[ir][ig][ib + 1], maxa[ir][ig][ib]);
                }
            }
        }
    }

    cout << maxa[sr][sg][sb] << "\n";

    return 0;
}