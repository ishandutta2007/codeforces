#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li
#define err if(debug_out)cout

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pld = pair<ld, ld>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = int(2e5) * 32 + 13;
const int LOGN = 20;
const int K = 22;
const int M = 1e9 + 7;
//const int M = 998244353;
//const int A = 26;
const ld eps = 1e-8;

mt19937 rnd(45768);

/*
5 4
12 21 17 1 2

2 3
1 3
*/

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

int cur = 1;
int g[N][2];
int sz[N];
int cnt[N];

void recalc(int v) {
    sz[v] = cnt[v] + (g[v][0] != -1 ? sz[g[v][0]] : 0) + (g[v][1] != -1 ? sz[g[v][1]] : 0);
}

void dfs1(int v) {
//    cout << "dfs1 " << v << endl;
//    cnt[v]--;
    int u = g[v][1];
    if(u != -1) {
        cnt[u] = 0;
        dfs1(u);

        if(sz[u] == 0) {
            g[v][1] = -1;
        }


    }

    if(g[v][0] != -1) {
        u = g[g[v][0]][0];
        if(u != -1) {
            cnt[u] = 0;
            dfs1(u);


            if(sz[u] == 0) {
                g[g[v][0]][0] = -1;
                recalc(g[v][0]);
                if(sz[g[v][0]] == 0) {
                    g[v][0] = -1;
                }
            }
        }
    }

    recalc(v);
}

void add(int x) {
//    cout << "add " << x << endl;
    int mx = 30;
    while(((1 << mx) & x) == 0)
        mx--;
//    cout << "mx " << mx << endl;

    int v = 0;
    for(int i = mx; i >= 0; i--) {
        int c = ((x >> i) & 1);

        if(g[v][c] == -1) {
            g[v][c] = cur;
            g[cur][0] = g[cur][1] = -1;
            cur++;
        }

        sz[v]++;
        v = g[v][c];
    }

    cnt[v]++;
    sz[v]++;

    dfs1(v);
}

vector<int> b;

void dfs2(int v, int x) {
    if(cnt[v]) {
        b.push_back(x);
    }
    for(int i = 0; i < 2; i++) {
        if(g[v][i] != -1) {
            dfs2(g[v][i], x * 2 + i);
        }
    }
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, p;
    cin >> n >> p;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

//    pw2[0] = 1;
//    for(int i = 1; i < N; i++) {
//        pw2[i] = pw2[i - 1] * 2ll % M;
//    }

    int mx = 29;

    sort(a.begin(), a.end());

    g[0][0] = g[0][1] = -1;
    for(int i = n - 1; i >= 0; i--) {
        add(a[i]);
//        break;
    }

    dfs2(0, 0);

    vector<int> cnt(30, 0);
    for(int x : b) {
//        cout << x << endl;
        for(int j = mx; j >= 0; j--) {
            if((1 << j) & x) {
                cnt[j]++;
                break;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < cnt.size() && i < p; i++) {
//        if(i == p - 1) {
//            ans = sum(ans, 1);
//        } else {
            int res = 0;
            int x = 0, y = 1;
            for(int j = i; j < p; j++) {
                res = sum(res, y);
                int tmp = y;
                y = sum(x, y);
                x = tmp;
            }
            ans = sum(ans, mul(res, cnt[i]));
//        }
    }

    cout << ans << endl;
}