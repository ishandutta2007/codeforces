#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> ans(n + 1);
    vector<vector<ll>> uh(n + 1);
    vector<int> u(n);
    for(auto &x : u)
        cin >> x;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        uh[u[i]].push_back(x);
    }

    for(int i = 1; i <= n; i++) {
        if(uh[i].empty())
            continue;
        sort(uh[i].begin(), uh[i].end());
        vector<ll> pf;
        ll cur = 0;
        for(auto x : uh[i]) {
            cur += x;
            pf.push_back(cur);
        }
        int k = uh[i].size();
        ll su = pf[k - 1];
        for(int j = 1; j <= k; j++) {
            int rm = k % j;
            if(rm == 0)
                ans[j] += su;
            else
                ans[j] += su - pf[rm - 1];
        }
    }

    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}