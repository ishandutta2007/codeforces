#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

vector <vector <int> > gr;
vector <int> c;
vector <bool> used;

int mink = INF;

void dfs(int v) {
    if (used[v]) {
        return;
    }
    //cout << v << "\n";
    used[v] = true;
    mink = min(mink, c[v]);
    for (int u : gr[v]) {
        dfs(u);
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
    int n, m;
    cin >> n >> m;
    c.resize(n);
    used.resize(n, false);
    gr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        gr[l].push_back(r);
        gr[r].push_back(l);
    }
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        mink = INF;
        dfs(i);
        sum += mink;
    }
    cout << sum;
}