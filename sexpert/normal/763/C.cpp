#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 10;
int n;
ll m, a[MAXN], inv[MAXN];
set<int> all;

bool check(int x, int d) {
    for(int i = 0; i < n; i++) {
        if(!all.count((x +(ll) i * d) % m))
            return false;
    }
    return true;
}

int main() {
    cin >> m >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        all.insert(a[i]);
    }
    inv[1] = 1;
    for(int i = 2; i < MAXN; i++)
        inv[i] = m - (m / i) * inv[m % i] % m;
    if(n == m) {
        cout << "0 1\n";
        return 0;
    }
    if(n == 1) {
        cout << a[0] << " " << 0 << '\n';
        return 0;
    }
    if(n == 2) {
        cout << min(a[0], a[1]) << " " << max(a[0], a[1]) - min(a[0], a[1]) << '\n';
        return 0;
    }
    ll s = 0, ss = 0;
    for(int i = 0; i < n; i++) {
        s = (s + a[i]) % m;
        ss = (ss + a[i] * a[i]) % m;
    }
    ll inn = (inv[n] * inv[n - 1]) % m;
    ll lit = ((ll)n * (n - 1)) % m;
    ll sqt = (lit * (2*n - 1)) % m;
    sqt = (sqt * inv[6]) % m;
    for(int i = 0; i < n; i++) {
        ll x = a[i];
        ll d = 2*s;
        d = (d * inn) % m;
        ll ex = (inv[n - 1] * 2) % m;
        ex = (ex * x) % m;
        d = (d - ex) % m;
        d = (d + m) % m;
        ll su = ((n * (x * x % m))%m + (lit * (d * x % m))%m + (sqt * (d * d % m)%m)) % m;
        if(su != ss)
            continue;
        if(check(x, d)) {
            cout << x << " " << d << '\n';
            return 0;
        }
    }
    cout << "-1\n";
}