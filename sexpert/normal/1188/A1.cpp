#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
int deg[MAXN];
bool can = true;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
    }
    for(int i = 1; i <= n; i++)
        if(deg[i] == 2) can = false;

    if(can) cout << "YES\n";
    else cout << "NO\n";
}