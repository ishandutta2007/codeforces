#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int n;
int val[N], l[N], r[N];
set<int> good;
bool ok[N];

void dfs(int v, int left = 1e9 + 7, int right = -1e9 - 7) {
    if (val[v] < left && val[v] >= right) good.insert(val[v]);
    if (l[v] != -1) dfs(l[v], min(left, val[v]), right);
    if (r[v] != -1) dfs(r[v], left, max(right, val[v]));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val[i] >> l[i] >> r[i];
        if (l[i] != -1) {
            l[i]--;
            ok[l[i]] = 1;
        }
        if (r[i] != -1) {
            r[i]--;
            ok[r[i]] = 1;
        }
    }
    int st = 0;
    while (ok[st]) st++;
    dfs(st);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!good.count(val[i])) ans++;
    }
    cout << ans;
    return 0;
}