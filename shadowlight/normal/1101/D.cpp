#include <bits/stdc++.h>
#define ll long long
#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-6;
const int SQ = 507;

int n;
vector <vector <int> > gr;
vector <int> a;

vector <vector <int> > ap;

int res = 1;

vector <int> getp(int v) {
    vector <int> z;
    int x = a[v];
    for (int i = 2; i <= SQ; i++) {
        if (x % i == 0) {
            z.push_back(i);
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x != 1) {
        z.push_back(x);
    }
    return z;
}

void dfs(int v, int p, int h, vector <int> &all, map <int, int> &maxh) {
    all.push_back(v);
    auto za = ap[v];
    for (int t : za) {
        maxh[t] = h;
    }
    for (int u : gr[v]) {
        if (u == p) continue;
        map <int, int> dh;
        vector <int> da;
        dfs(u, v, h + 1, da, dh);
        if (da.size() > all.size()) {
            swap(all, da);
            map <int, int> nt;
            for (int t : za) {
                nt[t] = dh[t];
            }
            dh = maxh;
            maxh = nt;
        }
        for (int x : da) {
            auto z = ap[x];
            for (int t : z) {
                if (!maxh.count(t) || !dh.count(t)) continue;
                res = max(res, maxh[t] + dh[t] - 2 * h + 1);
            }
        }
        for (int x : da) {
            auto z = ap[x];
            all.push_back(x);
            for (int t : z) {
                if (a[v] % t) continue;
                maxh[t] = max(maxh[t], dh[t]);
            }
        }
    }


}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    cin >> n;
    gr.resize(n);
    a.resize(n);
    bool fl = false;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] != 1) {
            fl = true;
        }
    }
    if (!fl) {
        cout << 0;
        return 0;
    }
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        gr[v].push_back(u);
        gr[u].push_back(v);
    }
    ap.resize(n);
    for (int i = 0; i < n; i++) {
        ap[i] = getp(i);
    }
    vector <int> all;
    map <int, int> maxh;
    dfs(0, -1, 0, all, maxh);
    cout << res;
}