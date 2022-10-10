#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    vector<int> val;
    string s;
    cin >> s;
    int cur = 0, st = 0;
    for(auto c : s) {
        if(c == '-')
            cur--;
        else
            cur++;
        st = max(st, -cur);
        val.push_back(cur);
    }
    int ali = 0;
    ll ans = 0;
    for(auto x : val) {
        ans += (st - ali + 1);
        ali = max(ali, -x);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}