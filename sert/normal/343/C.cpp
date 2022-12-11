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

ll a[N], b[N];
ll n, k, p, t, d, m, l, r, mm, uk, d2;
string s;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n >> m;
    fr(i, n) cin >> a[i];
    fr(i, m) cin >> b[i];
    b[m] = 9000000;
    b[m] = b[m] * b[m];

    l = -1;
    r = b[m] / 3;

    bool ok;

    while (r - l > 1) {
        ok = true;
        mm = (l + r) / 2;
        uk = 0;
        fr(i, n) {
            d = abs(a[i] - b[uk]);
            if (a[i] <= b[uk]) {
                while (d <= mm) {
                    uk++;
                    d = b[uk] - a[i];
                }
            }
            else {
                if (d <= mm) {
                    while (b[uk] <= a[i]) {
                        uk++;
                    }
                    d2 = d;
                    d *= 2;
                    d += b[uk] - a[i];
                    d2 += 2 * (b[uk] - a[i]);
                    while (d <= mm || d2 <= mm) {
                        uk++;
                        d = d + b[uk] - b[uk - 1];
                        d2 = d2 + 2 * (b[uk] - b[uk - 1]);
                    }
                }
            }
        }

        if (uk == m)
            r = mm;
        else
            l = mm;
    }

    cout << r;

    return 0;
}