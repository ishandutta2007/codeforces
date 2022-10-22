#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 1000000009;
const ll LINF = 1000000000000000009LL;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0LL;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    
    if (sum < 2LL) {
        cout << "-1\n";
        return;
    }
    
    ll csum = sum;
    vector<bool> pri(5, true);
    for (ll i = 1LL; i * i < sum; ++i) {
        pri.push_back(true);
    }
    vector<ll> p;
    for (ll i = 2LL; i < pri.size(); ++i) {
        if (pri[i]) {
            if (sum % i == 0LL) {
                while (csum % i == 0LL) {
                    csum /= i;
                }
                p.push_back(i);
            }
            for (ll j = i * i; j < pri.size(); j += i) {
                pri[j] = false;
            }
        }
    }
    if (csum > 1) {
        p.push_back(csum);
    }
    
    ll ans = -1LL;
    for (int ip = 0; ip < p.size(); ++ip) {
        ll cans = 0LL;
        ll del = 0LL;
        for (int i = 0; i < n; ++i) {
            del += a[i];
            if (del > 0LL) {
                del %= p[ip];
            }
            if (del > p[ip] / 2) {
                del -= p[ip];
            }
            if (del > 0LL) {
                cans += del;
            } else {
                cans -= del;
            }
        }
        //cout << p[ip] << " " << cans << "\n";
        if (ans == -1LL) {
            ans = cans;
        }
        ans = min(ans, cans);
    }
    
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t = 1;
    //cin >> t;
    for (int qq = 0; qq < t; ++qq) {
       solve();
    }
   
    return 0;
}