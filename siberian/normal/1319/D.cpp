#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;

#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

#define int ll
const int MAXN = 2e5 + 10;
int n, m;
vector<int> g[MAXN];
vector<int> gr[MAXN];
int k;
int p[MAXN];

void read() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[v].push_back(u);
        gr[u].push_back(v);
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> p[i];
        p[i]--;
    }
}

int d[MAXN];
const int INF = 1e9;

void build() {
    for (int i = 0; i < n; i++)
        d[i] = INF;
    d[p[k - 1]] = 0;
    queue<int> q;
    q.push(p[k - 1]);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto i : g[v]) {
            if (d[i] != INF) continue;
            d[i] = d[v] + 1;
            q.push(i);
        }
    }
    /*cout << "d = " << endl;
    for (int i = 0; i < n; i++)
        cout << d[i] << " ";
    cout << endl;*/
}

int ans1, ans2;

void solve1() {
    ans1 = 0;
    for (int i = 0; i < k - 1; i++) {
        ans1 += d[p[i]] != d[p[i + 1]] + 1;
    }
}

void solve2() {
    ans2 = 0;
    for (int i = 0; i < k - 1; i++) {
        if (d[p[i]] != d[p[i + 1]] + 1) {
            ans2++;
            continue;
        }
        for (auto j : gr[p[i]]) {
            if (j == p[i + 1]) continue;
            /*if (i == 1) {
                cout << j << endl;
            }*/
            if (d[p[i]] == d[j] + 1) {
                ans2++;
                break;
            }
        }
    }
}

void run() {
    build();
    solve1();
    solve2();
}

void write() {
    cout << ans1 << " " << ans2 << endl;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    read();
    run();
    write();
    return 0;
}