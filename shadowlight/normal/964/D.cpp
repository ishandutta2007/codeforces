#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

vector <vector <int> > gr;

vector <vector <vector <bool> > > nxt;
vector <vector <bool> > can;

void dfs(int v, int p) {
    vector <vector <int> > pred;
    pred.push_back({0, -1});
    for (int u : gr[v]) {
        if (u == p) continue;
        dfs(u, v);
        pred.push_back({-1, -1});
        int last = (int) pred.size() - 2;
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < 2; i++) {
                if (can[u][j] && pred[last][i] != -1) {
                    pred.back()[(i + j + 1) % 2] = j;
                }
            }
        }
    }
    int sz = pred.size();
    for (int st = 0; st < 2; st++) {
        int now = st;
        if (pred[sz - 1][st] == -1) {
            continue;
        }
        int rst = (st + 1) % 2;
        can[v][st] = true;
        nxt[v][st].resize(sz - 1);
        for (int i = sz - 1; i > 0; i--) {
            nxt[v][st][i - 1] = pred[i][now];
            now = (now + pred[i][now] + 1) % 2;
        }
    }
    //cout << v << " " << can[v][0] << " " << can[v][1] << "\n";
}

vector <int> order;

void rec(int v, int del, int p) {
    //cout << v << " " << del << "\n";
    int now = 0;
    for (int u : gr[v]) {
        if (u == p) continue;
        if (nxt[v][del][now]) {
            rec(u, 1, v);
        }
        now++;
    }
    order.push_back(v);
    now = 0;
    for (int u : gr[v]) {
        if (u == p) continue;
        if (!nxt[v][del][now]) {
            rec(u, 0, v);
        }
        now++;
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
    int n;
    cin >> n;
    gr.resize(n);
    nxt.resize(n, vector <vector <bool> > (2));
    can.resize(n, vector <bool> (2, false));
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        p--;
        if (p != -1) {
            gr[i].push_back(p);
            gr[p].push_back(i);
        }
    }
    dfs(0, -1);
    if (!can[0][0]) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    rec(0, 0, -1);
    for (int v : order) {
        cout << v + 1 << "\n";
    }
}