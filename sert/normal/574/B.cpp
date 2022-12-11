#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 4010;
const ll INF = 1e9;
const ll md = 1e9 + 7;
const ll o720 = 301388891;

int n, ans = INF;
bool u[4000][4000];
int sz[N], m, v1, v2;
vector <int> es[N];

int main() {

    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2;
        v1--;
        v2--;
        u[v1][v2] = u[v2][v1] = true;
        es[v1].push_back(v2);
        es[v2].push_back(v1);
        sz[v1]++;
        sz[v2]++;
    }

    for (int i = 0; i < n; i++) {
        int k = es[i].size();
        for (int j = 0; j < k; j++) {
            v1 = es[i][j];
            for (int ii = 0; ii < j; ii++) {
                v2 = es[i][ii];
                if (u[v1][v2])
                    ans = min(ans, sz[i] + sz[v1] + sz[v2]);
            }
        }
    }
    if (ans * 2 > INF) {
        cout << -1;
        return 0;
    }
    cout << ans - 6;

    return 0;
}