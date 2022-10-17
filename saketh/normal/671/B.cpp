#include <bits/stdc++.h>
using namespace std;

#define TRACE(x)
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto c=a; c!=b;) cout << *(c++) << " "; cout << endl)
#define WATCHC(V) TRACE(cout << #V" = "; WATCHR(V.begin(), V.end()))

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    ll N, K, tot = 0;
    cin >> N >> K;
    vector<ll> m(N);

    for (int i = 0; i < N; i++) {
        cin >> m[i];
        tot += m[i];
    }

    sort(m.begin(), m.end(), greater<ll>());
    WATCHC(m);

    ll each = tot / N;
    ll extra = tot % N;
    ll equi = 0;

    for (int i = 0; i < N; i++) {
        if (extra > 0) {
            equi += abs(m[i] - (each + 1));
            extra--;
        } else {
            equi += abs(m[i] - each);
        }
    }

    if (equi <= 2 * K) {
        if (tot % N == 0) cout << 0 << "\n";
        else cout << 1 << "\n";
        return 0;
    }

    ll high = m.front();
    ll lo = 1, hi = high - 1;
    while (lo <= hi) {
        ll mi = (lo + hi) / 2;
        ll cost = 0;
        for (int i = 0; i < N; i++) {
            if (m[i] > mi)
                cost += m[i] - mi;
        }
        if (cost <= K) {
            high = mi;
            hi = mi - 1;
        } else {
            lo = mi + 1;
        }
    }

    ll low = m.back();
    lo = low + 1, hi = high;
    while (lo <= hi) {
        ll mi = (lo + hi) / 2;
        ll cost = 0;
        for (int i = 0; i < N; i++) {
            if (m[i] < mi)
                cost += mi - m[i];
        }
        if (cost <= K) {
            low = mi;
            lo = mi + 1;
        } else {
            hi = mi - 1;
        }
    }

    cout << high - low << "\n";
    return 0;
}