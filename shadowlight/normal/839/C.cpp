#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e5 + 7;
const double EPS = 1e-8;
const int LOGN = 30;

vector <vector <int> > gr;

double sum = 0;

void dfs(int v, int p, double ver, ll h = 0) {
    ll cnt = gr[v].size();
    if (v) {
        cnt--;
    }
    if (!cnt) {
        //cout << h << " " << ver << endl;
        sum += h * ver;
    }
    for (int u : gr[v]) {
        if (u == p) continue;
        dfs(u, v, ver / cnt, h + 1);
    }
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
    #endif // MY
    ll n;
    cin >> n;
    gr.resize(n);
    for (int i = 1; i < n; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        gr[l].push_back(r);
        gr[r].push_back(l);
    }
    dfs(0, -1, 1, 0);
    cout.precision(20);
    cout << sum;
}