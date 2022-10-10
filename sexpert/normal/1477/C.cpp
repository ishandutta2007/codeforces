#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 5005;
ll x[MAXN], y[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int pv = 1;
    vector<int> ans = {1};
    set<int> rem;
    for(int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        if(i > 1)
            rem.insert(i);
    }
    int cur = 1;
    for(int j = 1; j <= n - 1; j++) {
        ll ma_di = -1;
        int tk = -1;
        for(auto &i : rem) {
            ll dx = x[cur] - x[i], dy = y[cur] - y[i];
            ll di = dx*dx + dy*dy;
            if(di > ma_di) {
                ma_di = di;
                tk = i;
            }
        }
        ans.push_back(tk);
        rem.erase(tk);
        cur = tk;
    }
    for(auto &i : ans)
        cout << i << " ";
    cout << '\n';
}