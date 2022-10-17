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

mt19937 rng(int(chrono::steady_clock::now().time_since_epoch().count()));

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    const int MAXL = 18;
    assert((1 << MAXL) > 2e5);

    int N, M;
    cin >> N >> M;

    vector<array<int, 3>> events;

    vector<pair<int, int>> intervals(N);
    for (int i = 0; i < N; i++) {
        cin >> intervals[i].second >> intervals[i].first;
    }
    sort(all(intervals));

    vi l(N), r(N);
    for (int i = 0; i < N; i++) {
        tie(r[i], l[i]) = intervals[i];
        events.push_back({ l[i], -1, i });
        events.push_back({ r[i], 1, i });
    }

    vi x(M), y(M);
    for (int i = 0; i < M; i++) {
        cin >> x[i] >> y[i];
        events.push_back({ x[i], 0, i });
    }

    vector<array<int, MAXL>> jump(N);
    for (int i = N - 1; i >= 0; i--) {
        fill(all(jump[i]), i);
    }
    vi query_start(M, -1);

    sort(all(events));
    int rm = -1;

    for (auto ev : events) {
        int type = ev[1];
        int inx = ev[2];

        if (type == -1) {
            if (rm == -1 || r[inx] > r[rm])
                rm = inx;
        } else if (type == 1) {
            jump[inx][0] = rm;
        } else if (type == 0) {
            query_start[inx] = rm;
        }
    }

    for (int i = N - 1; i >= 0; i--) {
        for (int b = 1; b < MAXL; b++) {
            jump[i][b] = jump[jump[i][b-1]][b-1];
        }
    }

    for (int q = 0; q < M; q++) {
        if (query_start[q] == -1) {
            cout << -1 << "\n";
        } else if (r[query_start[q]] >= y[q]) {
            cout << 1 << "\n";
        } else {
            int used = 1, loc = query_start[q];
            for (int b = MAXL - 1; b >= 0; b--) {
                int nxt = jump[loc][b];
                if (r[nxt] < y[q]) {
                    used += 1 << b;
                    loc = nxt;
                }
            }
            if (r[jump[loc][0]] >= y[q]) {
                cout << used + 1 << "\n";
            } else cout << -1 << "\n";
        }
    }

    return 0;
}