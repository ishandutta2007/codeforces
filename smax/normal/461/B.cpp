#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int x[100000];
vector<int> adj[100000];

void add(int &a, int b) {
    a = (a + b) % MOD;
}

int mul(int a, int b) {
    return (long long) a * b % MOD;
}

pair<int, int> dfs(int u) {
    // p.first -> no black vertices
    // p.second -> one black vertex
    pair<int, int> ret = {1, 0};
    for (int v : adj[u]) {
        pair<int, int> p = dfs(v);
        ret.second = mul(ret.second, p.first);
        add(ret.second, mul(ret.first, p.second));
        ret.first = mul(ret.first, p.first);
    }
    if (x[u])
        ret.second = ret.first;
    else
        add(ret.first, ret.second);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=1; i<n; i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    for (int i=0; i<n; i++)
        cin >> x[i];

    cout << dfs(0).second << "\n";

    return 0;
}