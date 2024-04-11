#include <bits/stdc++.h>

#define f first
#define s second
#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 5e5 + 13;
const int LOGN = 20;
const int K = 11;
const int M = 998244353;//1e9 + 7;
const int A = 26;

int sum(int a, int b) {
    return (a + b) % M;
//    a += b;
//    return (a >= M ? a - M : a);
}

int dif(int a, int b) {
    return sum(a, M - b);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

int pow2(int n, int k) {
    if(k == 0)
        return 1;

    int pw = pow2(n, k / 2);
    pw = mul(pw, pw);

    if(k % 2)
        return mul(pw, n);
    else
        return pw;
}
/*
*/

vector<pii> g[N], r[N];
int d[N];
int col[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int v, u, t;
        cin >> v >> u >> t;

        v--;
        u--;

        g[v].emplace_back(u, t);
        r[u].emplace_back(v, t);
    }

    for(int i = 0; i < n; i++) {
        d[i] = INF;
        col[i] = -1;
    }

    d[n - 1] = 0;
    col[n - 1] = 0;

    queue<int> q;
    q.push(n - 1);

    while(!q.empty()) {
        int v = q.front();
        q.pop();

        for(auto p : r[v]) {
            int u = p.f, t = p.s;

            if(d[u] < INF)
                continue;

            if(col[u] == -1 || col[u] != t) {
                col[u] = t ^ 1;
            } else {
                d[u] = d[v] + 1;
                q.push(u);
            }
        }
    }

    cout << (d[0] == INF ? -1 : d[0]) << endl;
    for(int i = 0; i < n; i++) {
        cout << (col[i] == -1 ? 0 : col[i]);
    }
    cout << endl;
}