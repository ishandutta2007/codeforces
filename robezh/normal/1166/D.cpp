#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

ll a, b, m;
vector<ll> res;

ll sum = 0;

bool dfs(ll mn, ll mx) {
    if(mx < mn || mx < a) return false;
//    cout << mn << ", " << mx << endl;
    if(mn <= a && a <= mx) {
        res.push_back(a);
        sum += a;
        return true;
    }
    ll n_mx = (mx - 1) / 2;
    ll n_mn = max(1LL, (mn - m - 1) / 2 + 1);
    if(dfs(n_mn, n_mx)) {
        ll cur_a = min(mx, 2 * sum + m);
        res.push_back(cur_a - sum);
        sum += cur_a - sum;
        return true;
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        cin >> a >> b >> m;
        res.clear();
        sum = 0;
        if(a == b) {
            cout << 1 << " " << b << "\n";
        }
        else if(dfs(b - m, b - 1)) {
            cout << res.size() + 1 << " ";
            for(ll x : res) cout << x << " ";
            cout << b;
            cout << "\n";
        }
        else cout << "-1" << "\n";
    }
}