//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
#define x first
#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
//using matr

const int INF = 1e9 + 13;
const int N = 6000 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;

mt19937 rnd(time(0));

void solve() {
    int x, y, p, q;
    cin >> x >> y >> p >> q;

    if(x * 1ll * q == y * 1ll * p) {
        cout << 0 << endl;
        return;
    }

    if(p == 0 || p == q) {
        cout << -1 << endl;
        return;
    }

    int l = 0, r = INF;
    while(r - l > 1) {
        int m = (l + r) / 2;

        li p1 = p * 1ll * m;
        li q1 = q * 1ll * m;

        if(p1 >= x && q1 >= y && p1 - x <= q1 - y) {
            r = m;
        } else {
            l = m;
        }
    }

    cout << r * 1ll * q - y << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}