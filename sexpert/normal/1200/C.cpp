#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, m, q;
    cin >> n >> m >> q;
    ll d = __gcd(n, m);
    n /= d;
    m /= d;
    while(q--) {
        ll t1, s1, t2, s2;
        cin >> t1 >> s1 >> t2 >> s2;
        t1--;
        s1--;
        t2--;
        s2--;
        s1 /= (t1 ? m : n);
        s2 /= (t2 ? m : n);
        cout << (s1 == s2 ? "YES\n" : "NO\n");
    }
}