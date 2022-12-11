#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false;
int a[N], b[N];
bool u[N];
vector<int> es[N];

void dfs(int v) {
    if (u[v]) return;
    u[v] = true;
    for (int w: es[v]) dfs(w);
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    for (int i = 0; i < n * 2; i++) es[i].clear();
    for (int i = 0; i < n; i++) {
        if (a[i] == 1 && b[i] == 1) {
            es[i].push_back(n + i);
            es[n + i].push_back(i);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] * a[j] == 1) {
                es[i].push_back(j);
                //es[j].push_back(i);
            }
            if (b[i] * b[j] == 1) {
                //es[i + n].push_back(j + n);
                es[j + n].push_back(i + n);
            }
        }
    }

    for (int i = 0; i < n * 2; i++) u[i] = false;

    dfs(0);

    if (u[m - 1] || u[m + n - 1]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tst = 1;
    //scanf("%d", &tst);
    //cin >> tst;
#ifdef MADE_BY_SERT
    D = true;    
    tst = 4;
    while (tst--) {
        solve();
    }
#else
    while (tst--) solve();
#endif
}