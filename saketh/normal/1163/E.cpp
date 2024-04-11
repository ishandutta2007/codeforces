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

    const int BITS = 20;

    int N;
    cin >> N;

    vector<pair<int, int>> vals(N);
    for (int i = 0, v; i < N; i++) {
        cin >> v;
        vals[i] = { v, v };
    }
    sort(all(vals));

    int rnk = 0;
    vi basis, prog;

    for (int bit = 0; bit < BITS; bit++) {
        int pvt = -1;
        for (int i = rnk; i < vals.size(); i++) {
            if ((vals[i].first & (1 << bit)) == 0) continue;
            if (pvt == -1 || vals[i].second < vals[pvt].second)
                pvt = i;
        }
        if (pvt == -1) break;

        swap(vals[pvt], vals[rnk]);
        prog.push_back(vals[rnk].second);

        for (int i = 0; i < vals.size(); i++) {
            if (i == rnk) continue;
            if (vals[i].first & (1ll << bit))
                vals[i].first ^= vals[rnk].first;
        }

        rnk++;

        bool ok = true;
        for (int v : prog)
            ok &= v < (1 << prog.size());
        if (ok) basis = prog;
    }

    cout << basis.size() << "\n";

    vi gray(1 << basis.size());
    gray[0] = 0;
    for (int p = 0; p < basis.size(); p++) {
        copy(gray.begin(), gray.begin() + (1 << p), gray.begin() + (1 << p));
        reverse(gray.begin() + (1 << p), gray.begin() + (1 << p) + (1 << p));
        for (int i = (1 << p); i < (1 << p) + (1 << p); i++) {
            gray[i] |= 1 << p;
        }
    }

    vi put;
    for (int g : gray) {
        put.push_back(0);
        for (int i = 0; i < basis.size(); i++)
            if ((g >> i)&1)
                put.back() ^= basis[i];
    }

    for (int v : put) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}