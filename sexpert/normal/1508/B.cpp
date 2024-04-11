#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    ll k;
    cin >> n >> k;

    if(n < 62 && k > 1LL << (n - 1)) {
        cout << "-1\n";
        return;
    }

    string s;
    for(int i = 0; i < n; i++)
        s += '0';
    k--;
    for(ll b = 0; b < min(60LL, (ll)(n - 1)); b++) {
        if((k >> b) & 1)
            s[n - 2 - b] = '1';
    }
    int cur = 1, sz = 1;
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        if(s[i] == '0') {
            for(int j = cur + sz - 1; j >= cur; j--)
                ans.push_back(j);
            cur += sz;
            sz = 1;
        }
        else
            sz++;
    }
    for(auto &x : ans)
        cout << x << " ";
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}