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

bool query(int x1, int y1, int x2, int y2, int N) {
    if (x1 > x2 || y1 > y2) return false;
    cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    assert( abs(x1 - x2) + abs(y1 - y2) >= N - 1);
    string res;
    cin >> res;
    if (res == "BAD") {
        exit(0);
    }
    return res == "YES";
}

void print(int N, vb &ops, vb &bops) {
    assert(ops.size() + bops.size() == 2 * N - 2);
    reverse(all(bops));
    ops.insert(ops.end(), all(bops));
    cout << "! ";
    for (bool dx : ops)
        cout << (dx ? 'D' : 'R');
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    // build the first half, preferring down
    vi x = { 1 }, y = { 1 };
    vb ops;
    for (int i = 0; i < N - 1; i++) {
        bool dx = query(x.back() + 1, y.back(), N, N, N);
        if (dx) {
            x.push_back(x.back() + 1);
            y.push_back(y.back());
        } else {
            x.push_back(x.back());
            y.push_back(y.back() + 1);
        }
        ops.push_back(dx);
    }

    // now build the second half backwards, preferring left
    vi bx = { N }, by = { N };
    vb bops;
    for (int i = 0; i < N - 1; i++) {
        bool dy = query(1, 1, bx.back(), by.back() - 1, N);
        if (dy) {
            bx.push_back(bx.back());
            by.push_back(by.back() - 1);
        } else {
            bx.push_back(bx.back() - 1);
            by.push_back(by.back());
        }
        bops.push_back(!dy);
    }

    print(N, ops, bops);
    return 0;
}