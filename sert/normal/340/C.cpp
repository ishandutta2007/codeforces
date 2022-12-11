#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <ctime>

#define mp make_pair
#define pb push_back
#define fr(i, n) for (int i = 0; i < int(n); i++)
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const ll N = 1e6 + 5;

ll gcd(ll aa, ll bb) {
    ll cc = aa % bb;
    while (cc != 0) {
        aa = bb;
        bb = cc;
        cc = aa % bb;
    }
    return bb;
}

ll a[N];
ll sa, sb;
ll ch, zn, h, n;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n;
    fr(i, n)
        cin >> a[i + 1];
    a[0] = 0;
    n++;
    sort(a, a + n);
    fr(i, n)
        sa += a[i];
    sb = 0;

    sa -= a[1];

    zn = n - 1;

    for (int i = 1; i < n; i++) {
        h = (a[i] * i - sb) + (sa - a[i] * (n - i - 1));
        sb += a[i];
        sa -= a[i + 1];
        ch += h;
    }

    h = gcd(ch, zn);

    cout << ch / h << " " << zn / h << "\n";

    return 0;
}