// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; ++i)

const int N = (int) 1e6 + 6, mod = 0;

int a[N], res = 0, ans[N], mark[N];
vector<int> adj[N];
int dfs(int v, int ep = -1) {
    if (mark[v]++) return -1;
    int ret = -1;
    for (int e : adj[v]) if (e != ep) {
        int u = e + a[e] - v;
        if (mark[u])
            ret = v;
        if (!mark[u]) {
            int out = dfs(u, e);
            if (out != -1)
                ret = out;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int root = -1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; a[i]--;
        adj[a[i]].push_back(i);
        adj[i].push_back(i);
        ans[i] = a[i];
        if (i == a[i])
            root = i;
    }
    for (int i = 0; i < n; ++i) if (!mark[i]) {
        int t = root != -1? mark[root]: 0;
        int cur = dfs(i);
        if (root != -1 && mark[root] != t) continue;
        res++;
        if (root == -1) root = cur;
        ans[cur] = root;
    }
    cout << res << '\n';
    for (int i = 0; i < n; ++i)
        cout << ans[i] + 1 << ' ';

}