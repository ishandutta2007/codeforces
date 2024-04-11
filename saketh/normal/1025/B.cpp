#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

vi factor(int arg) {
    vi res;
    int tmp = arg;
    for (ll p = 2; p * p <= arg; p++) {
        if (tmp % p == 0) {
            res.push_back(p);
            while (tmp % p == 0)
                tmp /= p;
        }
    }
    if (tmp != 1) res.push_back(tmp);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;
    vi a(N), b(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i];
    }

    vi cand;
    vi fa = factor(a[0]), fb = factor(b[0]);
    cand.insert(cand.end(), all(fa));
    cand.insert(cand.end(), all(fb));
    sort(all(cand));
    cand.erase(unique(all(cand)), cand.end());

    for (int v : cand) {
        bool ok = true;
        for (int i = 0; i < N; i++) {
            ok &= (a[i] % v == 0) || (b[i] % v == 0);
            if (!ok) break;
        }
        if (ok) {
            cout << v << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}