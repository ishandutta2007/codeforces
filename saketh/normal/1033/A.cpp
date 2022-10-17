#include <bits/stdc++.h>
using namespace std;

#define TRACE(x)
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

int classify(int qx, int qy, int x, int y) {
    assert(qx != x);
    assert(qy != y);
    assert(abs(qx - x) != abs(qy - y));

    int dx = x - qx;
    int dy = y - qy;

    return 2 * (dx > 0) + 1 * (dy > 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    int qx, qy;
    int ax, ay, bx, by;

    cin >> qx >> qy;
    cin >> ax >> ay >> bx >> by;

    int c1 = classify(qx, qy, ax, ay);
    int c2 = classify(qx, qy, bx, by);

    WATCH(c1);
    WATCH(c2);

    cout << (c1 == c2 ? "YES" : "NO") << endl;

    return 0;
}