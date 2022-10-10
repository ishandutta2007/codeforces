#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    k++;
    vector<int> v;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1')
            v.push_back(i);
    }
    v.push_back(n + k - 1);
    int ps = -k, pt = 0, ans = 0;
    while(ps < n) {
        if(ps + k <= v[pt] - k) {
            ans++;
            ps += k;
        }
        else {
            ps = v[pt];
            pt++;
        }
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