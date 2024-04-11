#include <bits/stdc++.h>
using namespace std;

int getInd(int n, int v1, int v2) {
    if (v1 > v2) swap(v1, v2);
    int ind = n * v1 - (v1 * (v1 + 1)) / 2 + v2 - v1 - 1;
    //cout << n << " " << v1 << " " << v2 << " = " << ind << "\n";
    return ind;
}

void go(int n, int k, int l, int r, int cur, vector<int> &ans) {
    if (l + 1 == r)
        return;
    int step = (r - l + k - 1) / k;
    for (int i = 0; i < k; i++) {
        int L = l + step * i;
        if (L >= r) break;
        int R = min(r, l + step * (i + 1));
        for (int j = L; j < R; j++)
            for (int x = R; x < r; x++)
                ans[getInd(n, j, x)] = cur;
        go(n, k, L, R, cur + 1, ans);
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> ans(n * (n - 1) / 2, -1);

    go(n, k, 0, n, 1, ans);

    cout << *max_element(ans.begin(), ans.end()) << "\n";
    for (int x : ans)
        cout << x << " ";
    cout << "\n";
}

int main() {
    int t = 1;
#ifdef SERT
    freopen("../a.in", "r", stdin);
    t += 3;
#endif
    while (t--) {
        solve();
    }
}