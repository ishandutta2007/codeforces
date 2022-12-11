#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <queue>
#include <cstdlib>
#include <cstring>

#define mp make_pair
#define pb push_back
#define fr(i, n) for (int i = 0; i < int(n); i++)
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const ll N = 1e6 + 5;

ll sum, h, n, ans, l = -1, r = 12345678, m, mx;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n;
    r *= r;
    for (int i = 0; i < n; i++) {cin >> h; sum += h; mx = max(mx, h);}
    while (r - l > 1) {
        m = (r + l) / 2;
        if (m * n - sum >= m) r = m; else l = m;
    }
    cout << max(r, mx);
    return 0;
}