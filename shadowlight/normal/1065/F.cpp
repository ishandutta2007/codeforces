#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

vector <vector <int> > gr;
vector <int> dpto, dpback;

int n, k;

vector <int> mh, h;

void dfs(int v, int p, int hnow) {
    h[v] = hnow;
    int sum = 0, maxk = 0;
    for (int u : gr[v]) {
        if (u == p) continue;
        dfs(u, v, hnow + 1);
        if (mh[v] == -1 || h[mh[v]] > h[mh[u]]) {
            mh[v] = mh[u];
        }
        if (h[mh[u]] - k > hnow) {
            maxk = max(maxk, dpto[u]);
            continue;
        }
        sum += dpback[u];
        maxk = max(maxk, dpto[u] - dpback[u]);
    }
    if (!gr[v].size()) {
        mh[v] = v;
        dpto[v] = 1;
        dpback[v] = 1;
    } else {
        dpback[v] = sum;
        dpto[v] = sum + maxk;
    }
    //cout << v << " " << dpback[v] << " " << dpto[v] << "\n";
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
    cin >> n >> k;
    gr.resize(n);
    dpto.resize(n, 0);
    dpback.resize(n, 0);
    mh.resize(n, -1);
    h.resize(n, 0);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        p--;
        gr[p].push_back(i);
    }
    dfs(0, -1, 0);
    cout << dpto[0];
}