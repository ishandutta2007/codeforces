#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m;

string bin(int sz, ll x) {
    string res;
    for(int i = 0; i < sz; i++) {
        res += to_string(x % 2);
        x /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

void solve() {
    cin >> n >> m;
    vector<ll> v;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        ll x = 0;
        for(ll b = 0; b < m; b++)
            x += ((ll(s[b] - '0')) << b);
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    ll tar = ((1LL << m) - n - 1)/2LL, cur = -1;
    int idx = 0;
    while(idx < n && v[idx] - cur - 1 <= tar) {
        tar -= (v[idx] - cur - 1);
        cur = v[idx];
        idx++;
    }
    cout << bin(m, cur + tar + 1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--)
        solve();
}