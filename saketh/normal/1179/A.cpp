#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;

template<typename T> void ckmin(T& a, const T& b) { a = min(a, b); }
template<typename T> void ckmax(T& a, const T& b) { a = max(a, b); }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q;
    cin >> N >> Q;

    int mv = 0;

    deque<int> dq;
    for (int i = 0, v; i < N; i++) {
        cin >> v;
        dq.push_back(v);
        ckmax(mv, v);
    }

    vector<array<int, 2>> ops;

    while (dq.front() != mv) {
        int e1 = dq.front(); dq.pop_front();
        int e2 = dq.front(); dq.pop_front();
        ops.push_back({ e1, e2 });
        dq.push_front(max(e1, e2));
        dq.push_back(min(e1, e2));
    }

    for (int q = 0; q < Q; q++) {
        ll m;
        cin >> m;

        if (--m < sz(ops)) {
            cout << ops[m][0] << " " << ops[m][1] << "\n";
        } else {
            int which = (m - sz(ops)) % (N - 1);
            cout << mv << " " << dq[1 + which] << "\n";
        }
    }

    return 0;
}