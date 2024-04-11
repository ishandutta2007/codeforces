#include <bits/stdc++.h>
using namespace std;

int a[100000], perm[100000], parent[100000], Rank[100000];
bool inArr[100000] = {};
long long Size[100000], ret[100000];

int Find(int u) {
    if (parent[u] != u)
        parent[u] = Find(parent[u]);
    return parent[u];
}

void Union(int u, int v) {
    u = Find(u), v = Find(v);
    if (u == v)
        return;

    if (Rank[u] > Rank[v]) {
        parent[v] = u;
        Size[u] += Size[v];
    } else if (Rank[u] < Rank[v]) {
        parent[u] = v;
        Size[v] += Size[u];
    } else {
        parent[u] = v;
        Size[v] += Size[u];
        Rank[v]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int i=0; i<n; i++) {
        cin >> perm[i];
        perm[i]--;
    }

    for (int i=0; i<n; i++) {
        parent[i] = i;
        Rank[i] = 0;
        Size[i] = a[i];
    }

    long long mx = 0;
    for (int i=n-1; i>=0; i--) {
        ret[i] = mx;
        inArr[perm[i]] = true;
        if (perm[i] > 0 && inArr[perm[i]-1])
            Union(perm[i], perm[i] - 1);
        if (perm[i] < n - 1 && inArr[perm[i]+1])
            Union(perm[i], perm[i] + 1);
        mx = max(mx, Size[Find(perm[i])]);
    }

    for (int i=0; i<n; i++)
        cout << ret[i] << "\n";

    return 0;
}