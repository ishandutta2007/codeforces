#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 3e5 + 13;
const int LOGN = 10;
const int K = 11;
const int M = 1e9 + 7;
const int A = 26;

/*
5 6
10010
0

3
1 2 4
2
2 5
0

1
3
2
4 5
*/

int p[N], is[N], sz[N], c0[N], c1[N], det[N], res[N];

pii get(int x) {
    if(p[x] == x)
        return {x, 0};
    auto pr = get(p[x]);
    p[x] = pr.f;
    is[x] = pr.s ^ is[x];
    return {p[x], is[x]};
}

int ans = 0;

void unite(int x, int y, int b) {
    pii px = get(x);
    pii py = get(y);

    if(py.f == px.f)
        return;

    if(sz[px.f] < sz[py.f])
        swap(px, py);

//    cout << "unite " << px.f << ' ' << px.s << ' ' << py.f << ' ' << py.s << ' ' << b << endl;
//    cout << c0[px.f] << ' ' << c1[px.f] << ' ' << c0[py.f] << ' ' << c1[py.f] << endl;

//    cout << "ans " << x << ' ' << y << ' ' << b << ' ' <<

    ans -= res[px.f];//min(c0[px.f], c1[px.f]);
    ans -= res[py.f];//min(c0[py.f], c1[py.f]);

    b ^= px.s ^ py.s;
    is[py.f] = b;

    if(b == 1) {
        c0[px.f] += c1[py.f];
        c1[px.f] += c0[py.f];
    } else {
        c0[px.f] += c0[py.f];
        c1[px.f] += c1[py.f];
    }

    if(det[py.f] != -1) {
        det[px.f] = det[py.f] ^ b;
    }

//    cout << "det : " << c0[px.f] << ' ' << c1[px.f] << ' ' << det[px.f] << endl;

    res[px.f] = (det[px.f] == -1 ? min(c0[px.f], c1[px.f]) : (det[px.f] == 1 ? c1[px.f] : c0[px.f]));

    p[py.f] = px.f;
    sz[px.f] += sz[py.f];

    ans += res[px.f];//min(c0[px.f], c1[px.f]);
}

vector<int> g[N];
vector<int> r[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    for(int i = 0; i < k; i++) {
        int c;
        cin >> c;

        g[i].resize(c);
        for(int j = 0; j < c; j++) {
            cin >> g[i][j];
            g[i][j]--;
            r[g[i][j]].push_back(i);
        }
    }

    for(int i = 0; i < k; i++) {
        p[i] = i;
        is[i] = 0;
        sz[i] = 1;
        c0[i] = 1;
        c1[i] = 0;
        det[i] = -1;
        res[i] = 0;
    }

    for(int i = 0; i < n; i++) {
//        cout << "i : " << i << endl;
        if(r[i].size() == 1) {
//            cout << "sagasgsfg " << endl;
            int v = r[i][0];
            pii pv = get(v);

            int b = (s[i] - '0') ^ pv.s;

            det[pv.f] = b;
            ans -= res[pv.f];
            res[pv.f] = (det[pv.f] == -1 ? min(c0[pv.f], c1[pv.f]) : (det[pv.f] == 1 ? c1[pv.f] : c0[pv.f]));
            ans += res[pv.f];
        } else if(r[i].size() == 2) {
            int v = r[i][0], u = r[i][1];
            unite(v, u, (s[i] - '0') ^ 1);
        }
//        for(int j = 0; j < k; j++)
//            cout << res[j] << ' ';
//        cout << endl;

        cout << ans << '\n';
//        if(i == 1)
//            return 0;
    }
}