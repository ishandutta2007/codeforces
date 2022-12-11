#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;
const ll md = 1e9 + 7;

int n, m, v1, v2, c[N];
set <int> es[N];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
int mx = 1e9;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
scanf("%d", c + i); mx = min(mx, c[i]);}
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &v1, &v2);
        v1 = c[v1 - 1];
        v2 = c[v2 - 1];
        //cerr << v1 << " " << v2 << "\n";
        if (v1 == v2) continue;
        es[v1].insert(v2);
        es[v2].insert(v1);
    }
    for (int i = 0; i <= 100000; i++)
        if (es[i].size() > es[mx].size())
            mx = i;
    cout << mx;



    return 0;
}