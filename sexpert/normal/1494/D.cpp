#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 5555;
int rep[MAXN], p[MAXN], sa[MAXN];
vector<array<int, 2>> edges[MAXN];

int find(int u) {
    return rep[u] == 0 ? u : rep[u] = find(rep[u]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            if(i == j)
                sa[i] = x;
            if(i < j)
                edges[x].push_back({i, j});
        }
    }

    for(int w = 1; w < MAXN; w++) {
        if(edges[w].empty())
            continue;
        for(auto &[u, v] : edges[w]) {
            int uu = find(u), vv = find(v);
            if(sa[uu] == w && sa[vv] == w)
                continue;
            if(sa[uu] != w && sa[vv] != w) {
                n++;
                sa[n] = w;
                p[uu] = rep[uu] = p[vv] = rep[vv] = n;
            }
            else {
                if(sa[uu] == w)
                    p[vv] = rep[vv] = uu;
                else
                    p[uu] = rep[uu] = vv;
            }
        }
    }

    cout << n << '\n';
    for(int i = 1; i <= n; i++)
        cout << sa[i] << " ";
    cout << '\n';
    cout << n << '\n';
    for(int i = 1; i < n; i++)
        cout << i << " " << p[i] << '\n';
}