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

    int N, v;
    cin >> N;

    vvi eq(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> v;
        eq[N - v].push_back(i);
    }

    int lb = 0;
    vi res(N, -1);
    for (int sz = 1; sz <= N; sz++) {
        if (eq[sz].size() % sz != 0) {
            cout << "Impossible\n";
            return 0;
        }
        while (!eq[sz].empty()) {
            lb++;
            for (int i = 0; i < sz; i++) {
                res[eq[sz].back()] = lb;
                eq[sz].pop_back();
            }
        }
    }

    cout << "Possible\n";
    for (int v : res) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}