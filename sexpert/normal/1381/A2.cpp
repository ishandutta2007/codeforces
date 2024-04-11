#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int flp = 0, l, r, n;
string s, t;

int val(int ps) {
    if(flp)
        return (s[r - ps] - '0') ^ 1;
    return (s[l + ps] - '0');
}

void solve() {
    cin >> n >> s >> t;
    l = 0, r = n - 1;
    flp = 0;
    vector<int> ans;
    for(int i = n - 1; i >= 1; i--) {
        if(val(i) == (t[i] - '0'))
            continue;
        if(val(0) == (t[i] - '0'))
            ans.push_back(0);
        ans.push_back(i);
        if(flp == 1) {
            l += r - l - i;
            r--;
        }
        else {
            r = l + i;
            l++;
        }
        flp ^= 1;
    }
    if(val(0) != t[0] - '0')
        ans.push_back(0);
    cout << ans.size() << '\n';
    for(auto x : ans)
        cout << x + 1 << ' ';
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