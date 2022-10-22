#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 1000000007;
const ld EPS = 1e11;
const ll INFL = 1e16;
const int INF = 1e9 + 7;

ll mul(ll a, ll b) {
    return (a * b) % MOD;
}

ll add(ll& a, ll b) {
    ll ans = a + b;
    while (ans >= MOD) {
        ans -= MOD;
    }
    return ans;
}

ll sub(ll& a, ll b) {
    return add(a, MOD - b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> a[i];
    }

    vector<ll> mad(n, 1), mid(n, 1), eqd(n, 0), leqd(n, 0);
    for (int k = 1; k <= n * 2 - 2; ++k) {
        vector<ll> nmad(n, 0), nmid(n, 0), neqd(n, 0), nroo(n, 0);
        if (k == 1) {
            nmid[0] = a[0];
            nroo[0] = a[0];
            for (int i = 1; i < n - 1; ++i) {
                nmad[i] = nmid[i - 1];
                nmid[i] = mul(nmid[i - 1], a[i]);
            }
            nmad[n - 1] = nmid[n - 2];
            mid = move(nmid);
        }
        else {
            if (k == 2) {
                for (int i = 1; i < n; ++i) {
                    neqd[i] = mul(mul(mid[i - 1], a[i - 1] - 1), 500000004LL);
                }
            }
            else {
                for (int i = 1; i < n; ++i) {
                    neqd[i] = mul(leqd[i - 1], mul(a[i - 1], a[i - 1]));
                }
            }
            for (int i = 1; i < n; ++i) {
                nmad[i] = mul(mad[i - 1], a[i - 1]);
                nmad[i] = add(nmad[i], mul(mul(eqd[i - 1], a[i - 1]), 2LL));
            }
        }

        leqd = move(eqd);
        eqd = move(neqd);
        mad = move(nmad);

        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = add(ans, mad[i]);
            ans = add(ans, eqd[i]);
        }

        cout << ans << " ";
    }

    return 0;
}