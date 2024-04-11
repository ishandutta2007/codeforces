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

    vi a(N), b(N);
    char c;
    for (int i = 0; i < N; i++) {
        cin >> c;
        a[i] = c - '0';
    }
    for (int i = 0; i < N; i++) {
        cin >> c;
        b[i] = c - '0';
    }

    vi calc = a;
    vll moves(N-1);
    ll tot = 0;
    for (int i = 0; i < N - 1; i++) {
        moves[i] = b[i] - calc[i];
        calc[i+1] += moves[i];
        tot += abs(moves[i]);
    }

    if (calc.back() != b.back()) {
        cout << -1 << endl;
        return 0;
    }

    queue<int> q;
    vb inq(N-1);

    auto movable = [&](int i) {
        if (i < 0 || i >= N-1) return false;
        if (moves[i] == 0) return false;
        if (moves[i] > 0)
            return a[i] < 9 && a[i+1] < 9;
        return a[i] > !i && a[i+1] > 0;
    };

    for (int i = 0; i < N - 1; i++) {
        if (movable(i)) {
            q.push(i);
            inq[i] = true;
        }
    }

    auto sgn = [](ll mv) { return mv > 0 ? 1 : -1; };

    cout << tot << "\n";
    for (int m = 0; m < min(tot, 100000ll); m++) {
        while (!movable(q.front())) {
            inq[q.front()] = false;
            q.pop();
        }
        int inx = q.front();
        cout << inx + 1 << " " << sgn(moves[inx]) << "\n";
        a[inx] += sgn(moves[inx]);
        a[inx + 1] += sgn(moves[inx]);
        moves[inx] -= sgn(moves[inx]);

        if (movable(inx-1) && !inq[inx-1]) {
            q.push(inx-1);
            inq[inx-1] = true;
        }
        if (movable(inx+1) && !inq[inx+1]) {
            q.push(inx+1);
            inq[inx+1] = true;
        }
    }

    return 0;
}