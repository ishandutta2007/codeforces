#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

vector <vector <int> > gr;
int n;

vector <int> col;
int cnt = 0;

void dfs(int v, int p = -1, int c = 0) {
    int c1 = c;
    if (c != col[v]) {
        c1 = col[v];
        cnt++;
    }
    for (int u : gr[v]) {
        if (u == p) continue;
        dfs(u, v, c1);
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
    col.resize(n, 0);
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        x--;
        gr[x].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> col[i];
    }
    dfs(0);
    cout << cnt;
}