#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;
const ll md = 1e9 + 7;

string s;
ll n, l, m, c, r, babki;
ll p[N], k[N], a[N];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> s;
    n = s.length();
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') a[0]++;
        if (s[i] == 'S') a[1]++;
        if (s[i] == 'C') a[2]++;
    }

    for (int i = 0; i < 3; i++) cin >> k[i];
    for (int i = 0; i < 3; i++) cin >> p[i];
    cin >> babki;

    ll l = 0;
    ll r = 1e13;
    ll m, c;

    while (r - l > 1) {
        m = (l + r) / 2;
        c = 0;
        for (int i = 0; i < 3; i++)
            c += max(0ll, a[i] * m - k[i]) * p[i];
        if (c <= babki)
            l = m;
        else
            r = m;

    }
    cout << l;



    return 0;
}