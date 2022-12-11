#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <utility>

#define y1 yy1
#define ff first
#define ss second

typedef long long ll;
typedef long double ld;

using namespace std;

const ll N = 1e6 + 34;

ll n, a[N], p[N], s[N], ans = 1234567890, t, d, m;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n >> m >> d;
    n = n * m;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for (int i = 1; i < n; i++)
    if ((a[i] - a[0]) % d) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < n; i++) p[i + 1] = p[i] + a[i];
    for (int i = n - 1; i >= 0; i--) s[i] = s[i + 1] + a[i];

    for (int i = 0; i < n; i++) {
        t = (-p[i] + i * a[i] - (n - i - 1) * a[i] + s[i + 1]) / d;
        if (t < ans) ans = t;
    }

    cout << ans;

    return 0;
}