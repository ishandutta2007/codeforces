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

void solve() {
    int N;
    cin >> N;

    vi nxt(N);
    for (int i = 0; i < N; i++) {
        cin >> nxt[i];
        if (nxt[i] > 0) --nxt[i];
    }

    vi res(N);

    queue<array<int, 3>> go({ {0, 0, N} });
    bool fail = false;
    while (!go.empty()) {
        auto p = go.front();
        go.pop();

        int inx = p[0], used = p[1], lim = p[2];

        if (nxt[inx] == -1) {
            res[inx] = used + 1;
            if (inx + 1 < lim) go.push({ inx + 1, used + 1, lim });
        } else {
            if (nxt[inx] > lim) { fail = true; break; }

            int gap = nxt[inx] - inx - 1;
            res[inx] = used + gap + 1;
            if (inx + 1 < nxt[inx]) go.push({ inx + 1, used, nxt[inx] });
            if (nxt[inx] < lim) go.push({ nxt[inx], used + gap + 1, lim });
        }
    }

    if (!fail) {
        for (int v : res)
            cout << v << " ";
        cout << "\n";
    } else {
        cout << -1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        solve();
    }

    return 0;
}