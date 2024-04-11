#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> p;
int n;
ll x, y, a, b;
ll k;

bool can(ll am) {
    ll lc = a * b / __gcd(a, b);
    ll xab = am / lc;
    ll xa = am / a - xab, xb = am / b - xab;
    ll tot = 0;
    int cur = 0;
    while(xab--) {
        tot += p[cur] * (x + y);
        cur++;
    }
    if(x > y) {
        while(xa--) {
            tot += p[cur] * x;
            cur++;
        }
        while(xb--) {
            tot += p[cur] * y;
            cur++;
        }
    }
    else {
        while(xb--) {
            tot += p[cur] * y;
            cur++;
        }
        while(xa--) {
            tot += p[cur] * x;
            cur++;
        }
    }
    return tot >= k;
}

void solve() {
    cin >> n;
    p.assign(n, 0);
    for(auto &x : p) {
        cin >> x;
        x /= 100;
    }
    sort(p.rbegin(), p.rend());
    cin >> x >> a >> y >> b >> k;
    if(!can(n)) {
        cout << "-1\n";
        return;
    }
    int lo = 1, hi = n;
    while(lo < hi) {
        int mi = (lo + hi)/2;
        if(can(mi))
            hi = mi;
        else
            lo = mi + 1;
    }
    cout << lo << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while(q--)
        solve();    
}