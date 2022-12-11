#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
const ll N = 134;

ll n, q, x, y, l, r, L, R, p, len;
pair <ll, ll> c[N];
bool u[N][N], use[N];

bool go(ll v1, ll v2) {
    if (c[v1].first < c[v2].second && c[v1].first > c[v2].first)
        return true;
    if (c[v1].second < c[v2].second && c[v1].second > c[v2].first)
        return true;
    return false;
}

bool dfs(ll v) {
    use[v] = true;
    if (v == y)
        return true;
    for (int i = 0; i < len; i++)
        if (u[v][i] && !use[i])
            if (dfs(i))
                return true;
    return false;
}

int main() {
    ///freopen("a.in", "r", stdin);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> q >> x >> y;
        if (q == 1) {
            c[len++] = make_pair(x, y);
            for (int j = 0; j < len - 1; j++) {
                if (go(j, len - 1))
                    u[j][len - 1] = true;
                if (go(len - 1, j))
                    u[len - 1][j] = true;
            }
        } else {
            x--;
            y--;
            for (int j = 0; j < len; j++)
                use[j] = false;
            if (dfs(x))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}