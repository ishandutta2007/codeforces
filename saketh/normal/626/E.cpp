#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 100;

int N;
ll val[MAXN];
ll pref[MAXN];

ll read(int l, int r) {
    ll ans = pref[r];
    if(l > 0) ans -= pref[l-1];
    return ans;
}

double BEST;
int a, b, c, d, e, f;

void print_best() {
    int size = b - a + 1 + c - d + 1 + f - e + 1;
    cout << size << "\n";

    for (int i = a; i <= b; i++)
        cout << val[i] << " ";
    for (int i = c; i <= d; i++)
        cout << val[i] << " ";
    for (int i = e; i <= f; i++)
        cout << val[i] << " ";

    cout << "\n";
}

double max_skew(int m1, int m2) {
    int l1 = 0, r1 = m1 - 1;
    int l2 = m2 + 1, r2 = N - 1;

    int melt = m2 - m1 + 1;
    int below = r1 - l1 + 1;
    int above = r2 - l2 + 1;

    if (below <= 0 || above <= 0) return 0;

    double median = read(m1, m2) / double(melt);

    int lo = 1, hi = min(below, above);

    while (lo <= hi) {
        int mi = (lo + hi) / 2;

        int nelt = melt + 2 * mi;
        ll sum = read(m1, m2) + read(r1 - mi + 1, r1) + read(r2 - mi + 1, r2);

        double candidate = sum / double(nelt) - median;
        if (candidate > BEST) {
            BEST = candidate;
            a = r1 - mi + 1;
            b = r1;
            c = m1;
            d = m2;
            e = r2 - mi + 1;
            f = r2;
        }

        bool extend = false;
        if (mi < min(below, above)) {
            ll next_pair = val[r1 - mi] + val[r2 - mi];

            // want to know if (next_pair / 2) >= (sum / nelt)
            // which means next_pair * nelt >= 2 * sum
            if (next_pair * nelt >= 2 * sum) {
                extend = true;
            }
        }

        if (extend) {
            lo = mi + 1;
        } else {
            hi = mi - 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> val[i];
    }

    sort(val, val + N);

    for (int i = 0; i < N; i++) {
        pref[i] = val[i];
        if (i) pref[i] += pref[i-1];
    }

    BEST = 0;
    a = 0, b = -1;
    c = 0, d = 0;
    e = 0, f = -1;

    // try single-value median
    for (int i = 0; i < N; i++) {
        max_skew(i, i);
    }

    // try double-value median
    for (int i = 0; i + 1 < N; i++) {
        max_skew(i, i+1);
    }

    print_best();
    return 0;
}