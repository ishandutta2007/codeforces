#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;

const int N = 5e5 + 13;

int n;
vector<int> a[N];
int l[N], r[N];

int dfs1(int v, int p, int ind, int lst) {
    if(p != -1) {
        l[v] = r[p] - ind - 1;
        r[v] = lst + a[v].size();//sz[v];
    } else {
        l[v] = 1;
        r[v] = 2 + a[v].size();
    }

    int lst1 = r[v];
    int ind1 = 0;
    for(auto u : a[v]) {


        if(u != p) {
            lst1 = dfs1(u, v, ind1, lst1);

            ind1++;
        }
    }

    return lst1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        a[v].push_back(u);
        a[u].push_back(v);
    }

    //dfs(0, -1);

    dfs1(0, -1, 1, 1);

    for(int i = 0; i < n; i++)
        cout << l[i] << ' ' << r[i] << endl;
}