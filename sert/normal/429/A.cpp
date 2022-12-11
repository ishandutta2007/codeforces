#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;
const int M = 200;

int n, m, v1, v2;
int a[N], g[N];
vector <int> es[N], ans;

void dfs(int v, int pr, bool chs, bool chk) {
    if (chs) a[v] = !a[v];
    swap(chs, chk);
    if (a[v] != g[v]) {
        ans.push_back(v + 1);
        chk = !chk;
    }
    for (int i = 0; i < es[v].size(); i++) 
        if (es[v][i] != pr)
            dfs(es[v][i], v, chs, chk);
}

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> v1 >> v2;
        v1--;
        v2--;
        es[v1].push_back(v2);
        es[v2].push_back(v1);
    }
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> g[i];
    dfs(0, -1, 0, 0);

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << "\n";
    //return 0;
}