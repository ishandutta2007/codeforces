#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll N = 1e6 + 7;
const ll md = 1e9 + 7;
const ll p1 = 37;
const ll p2 = 2011;

ll h1[N], h2[N], n, o1[N], o2[N];
pair <ll, ll> pal[N];
string s;
ll a[N], o[N];
ll sf[N], st1[N], st2[N];
pair <ll, ll> hh, oo;
ll ans, len;

int main() {
    ///freopen("a.in", "r", stdin);
    cin >> s;
    n = s.length();
    for (int i = 0; i < n; i++)
        o[n - i - 1] = a[i] = s[i] - 'a' + 1;
    h1[0] = h2[0] = 0;
    st1[0] = st2[0] = 1;
    for (int i = 0; i < n; i++) {
        st1[i + 1] = (st1[i] * p1) % md;
        st2[i + 1] = (st2[i] * p2) % md;
        h1[i + 1] = (h1[i] * p1 + a[i]) % md;
        h2[i + 1] = (h2[i] * p2 + a[i]) % md;
        o1[i + 1] = (o1[i] * p1 + o[i]) % md;
        o2[i + 1] = (o2[i] * p2 + o[i]) % md;
    }

    sf[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        sf[i] = sf[i + 1] + 1;
        hh = oo = make_pair(a[i], a[i]);
        pal[len++] = make_pair(i, i);

        for (int j = i + 1; j < n; j++) {
            hh.first = (hh.first * p1 + a[j]) % md;
            hh.second = (hh.second * p2 + a[j]) % md;
            oo.first = (oo.first + a[j] * st1[j - i]) % md;
            oo.second = (oo.second + a[j] * st2[j - i]) % md;
            if (hh == oo) {
                sf[i]++;
                pal[len++] = make_pair(i, j);
            }
        }
    }

    for (int i = 0; i < len; i++)
        ans += sf[pal[i].second + 1];

    cout << ans << "\n";

    return 0;
}