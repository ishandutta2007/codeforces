#include <bits/stdc++.h>
using namespace std;

vector<int> root, children[2000];

int dfs(int u) {
    int ret = 0;
    for (int v : children[u])
        ret = max(ret, dfs(v));
    return ret + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int p;
        cin >> p;
        if (p == -1)
            root.push_back(i);
        else
            children[p-1].push_back(i);
    }

    int ret = 0;
    for (int i : root)
        ret = max(ret, dfs(i));

    cout << ret << "\n";

    return 0;
}