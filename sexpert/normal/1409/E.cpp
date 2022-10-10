#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> ans(n), smx(n), pts(n);
    for(auto &x : pts)
        cin >> x;
    for(auto &x : ans)
        cin >> x;
    sort(pts.rbegin(), pts.rend());
    queue<int> Q;
    int cur = n - 1;
    for(auto &x : pts) {
        Q.push(x);
        while(Q.front() > x + k)
            Q.pop();
        ans[cur] = Q.size();
        smx[cur] = max(ans[cur], (cur == n - 1 ? 0 : smx[cur + 1]));
        cur--;
    }
    int res = 0;
    for(int i = 0; i < n; i++) {
        int ta = ans[i];
        res = max(res, ta + (i + ta < n ? smx[i + ta] : 0));
    }
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}