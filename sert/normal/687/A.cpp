#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.2
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
const int N = 1e6 + 34;
const int INF = 1e9 + 34;
typedef long long ll;

vector <int> ans[2];
vector <int> es[N];
int n, m, v1, v2;
int c[N];

void dfs(int v, int q) {
    if (c[v] && c[v] != q + 1) {
        cout << "-1";
        exit(0);
    }

    if (c[v])
        return;

    c[v] = q + 1;
    ans[q].push_back(v + 1);


    for (int w: es[v]) {
        dfs(w, 1 - q);
    }
}

int main() {
    init();

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2;
        v1--;
        v2--;
        es[v1].push_back(v2);
        es[v2].push_back(v1);
    }

    for (int i = 0; i < n; i++)
        if (!c[i])
            dfs(i, 0);

    for (int i = 0; i < 2; i++) {
        cout << ans[i].size() << "\n";
        for (int w: ans[i])
            cout << w << " ";
        cout << "\n";
    }

    return 0;
}