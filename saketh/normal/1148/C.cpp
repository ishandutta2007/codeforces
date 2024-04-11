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

    int N;
    cin >> N;

    vi perm(N), loc(N);
    for (int i = 0; i < N; i++) {
        cin >> perm[i];
        loc[--perm[i]] = i;
    }

    vector<pair<int, int>> moves;
    auto move = [&](int i, int j) {
        assert(abs(i - j) >= N/2);
        moves.emplace_back(i, j);
        swap(loc[perm[i]], loc[perm[j]]);
        swap(perm[i], perm[j]);
    };

    int mid = N / 2;

    // first fix 0
    if (loc[0] != 0) {
        if (loc[0] >= mid) {
            move(loc[0], 0);
        } else {
            move(loc[0], N - 1);
            move(N - 1, 0);
        }
    }
    assert(loc[0] == 0);

    // now fix N - 1
    if (loc[N - 1] != N - 1) {
        if (loc[N - 1] < mid) {
            move(loc[N - 1], N - 1);
        } else {
            move(0, N - 1);
            move(loc[N - 1], 0);
            move(0, N - 1);
        }
    }
    assert(loc[N - 1] == N - 1);

    // now fix others
    for (int i = 1; i < N - 1; i++) {
        if (loc[i] == i) continue;
        int li = loc[i];
        if ((i < mid) ^ (li < mid)) {
            // opposite
            move(0, li);
            move(N-1, i);
            move(0, N - 1);
            move(0, li);
            move(N-1, i);
        } else if (i < mid) {
            // both below
            move(i, N - 1);
            move(li, N - 1);
            move(i, N - 1);
        } else {
            // both over
            move(i, 0);
            move(li, 0);
            move(i, 0);
        }
    }

    if (loc[0] != 0) {
        move(0, N - 1);
    }

    for (int i = 0; i < N; i++)
        assert(perm[i] == i);

    cout << moves.size() << "\n";
    for (auto p : moves)
        cout << p.first + 1 << " " << p.second + 1 << "\n";

    return 0;
}