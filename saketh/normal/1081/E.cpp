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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, val;
    cin >> N;

    vi roots;
    for (int i = 0; i < N / 2; i++) {
        cin >> val;

        int lv = i ? roots.back() : 0;
        int ai = -1, bi = -1;

        for (int p = 1; p * p <= val; p++) {
            if (val % p) continue;
            int q = val / p;
            if ((p + q) % 2) continue;

            int b = (p + q) / 2;
            int a = (q - p) / 2;

            if (a <= lv) continue;
            if (ai == -1 || b < bi) {
                ai = a, bi = b;
            }
        }

        if (ai == -1) {
            cout << "No\n";
            return 0;
        }

        roots.push_back(ai);
        roots.push_back(bi);
    }

    cout << "Yes\n";
    ll pv = 0;
    for (int i = 0; i < roots.size(); i++) {
        ll sq = roots[i] * 1ll * roots[i];
        cout << sq - pv << " ";
        pv = sq;
    }
    cout << endl;

    return 0;
}