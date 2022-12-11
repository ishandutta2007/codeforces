#include <iostream>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#include <deque>

#define fab(i, a, b) for(int i = a; i <= b; i++)
#define fdown(i, n) for(int i = n - 1; i >= 0; i--)
#define fr(i, n) for(int i = 0; i < n; i++)
#define mp make_pair
#define pb push_back
#define pint pair <int, int>
#define vint vector <int>
#define vpint vector < pair <int, int> >
#define ff first
#define ss second
#define cpr(n) cout.precision(n);

typedef long long ll;
typedef long double ld;

const ll inf = 1e9;
const ld eps = 1e-9;
const ll N = 1e6;
const ll M = 1e4;

using namespace std;

void ret(string s)
{
  cout << s;
  exit(0);
}

ll x, y, n, c, l = 0, r, m, h;

ll get(ll t){
    ll ans = 2 * t * (t + 1) + 1;
    if (y - n + t > 0) ans -= (y - n + t) * (y - n + t);
    if (x - n + t > 0) ans -= (x - n + t) * (x - n + t);
    if (t - x + 1 > 0) ans -= (t - x + 1) * (t - x + 1);
    if (t - y + 1 > 0) ans -= (t - y + 1) * (t - y + 1);

    h = t - (n - x + 1) - (n - y + 1) + 1;
    if (h > 0) ans += ((h + 1) * h) / 2;

    h = t - x - (n - y + 1) + 1;
    if (h > 0) ans += ((h + 1) * h) / 2;

    h = t - (n - x + 1) - y + 1;
    if (h > 0) ans += ((h + 1) * h) / 2;

    h = t - x - y + 1;
    if (h > 0) ans += ((h + 1) * h) / 2;

    return ans;
}

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n >> x >> y >> c;
    r = 2 * n;
    while(r - l > 0){
        m = (l + r) / 2;
        h = get(m);
        if (h >= c)
            r = m;
        else
            l = m + 1;
    }
    cout << r;
    return 0;
}