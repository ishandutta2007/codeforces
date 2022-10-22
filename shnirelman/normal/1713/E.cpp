#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const li INF64 = 2e18 + 13;
const int M = 998244353;
//const int A = 1e6 + 13;
const int N = 1e6 + 13;
const int B = 400;
const int LOGN = 20;

mt19937 rnd(7476);

int p[N], sz[N], inv[N];

pii getp(int x) {
    if(p[x] == x)
        return pii(x, 0);
    else {
        pii res = getp(p[x]);
        p[x] = res.f;
        inv[x] ^= res.s;
        return pii(p[x], inv[x]);
    }
}

bool unite(int x, int y, int z) {
    pii rx = getp(x);
    pii ry = getp(y);

//    cout << "unite " << x << ' ' << y << ' ' << z << endl;
//    cout << " unite2 " << rx.f << ' ' << rx.s << "  " << ry.f << ' ' << ry.s << endl;

    x = rx.f;
    y = ry.f;

    if(x == y) {
        return (z ^ rx.s ^ ry.s) == 0;
    }

    if(sz[x] < sz[y])
        swap(x, y);

    p[y] = x;
    inv[y] = (rx.s ^ ry.s ^ z);
    sz[x] += sz[y];
    return true;
}

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
    }

    for(int i = 0; i < n; i++) {
        p[i] = i;
        sz[i] = 1;
        inv[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
//            cout << i << ' ' << j << endl;
            if(a[i][j] < a[j][i]) {
                if(!unite(i, j, 0)) {
                    swap(a[i][j], a[j][i]);
                }

            } else if(a[i][j] > a[j][i]) {
                if(unite(i, j, 1)) {
                    swap(a[i][j], a[j][i]);
                }

            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}