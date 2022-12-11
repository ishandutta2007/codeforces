//made by Sert
#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9 + 34;
const int N = (int)1e6 + 34;

typedef long long ll;

void solve() {
    int n;
    scanf("%d", &n);
    vector<vector<int>> es(n);
    for (int i = 1; i < n; i++) {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        v1--;
        v2--;
        es[v1].push_back(v2);
        es[v2].push_back(v1);
    }
    int mx = 0;
    for (int i = 0; i < n; i++) {
        if ((int)es[i].size() > (int)es[mx].size()) mx = i;
    }
    for (int i = 0; i < n; i++) {
        if ((int)es[i].size() > 2 && i != mx) {
            printf("No\n");
            return;
        }
    }
    printf("Yes\n%d\n", es[mx].size());
    for (int i = 0; i < n; i++) {
        if ((int)es[i].size() == 1 && i != mx) {
            printf("%d %d\n", mx + 1, i + 1);
        }
    }
}

int main() {
#ifdef MADE_BY_SERT
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    solve();
    solve();
#endif
    solve();
    return 0;
}