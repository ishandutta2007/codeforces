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

string s;
ll n, m, k, t, p, q, ans;
ll a[N], b[N], c[N];

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= n; i++) {
        if (i == 1) b[i] = 0;
        else b[i] = (c[i - 1] <= c[i - 2] ? 1 : b[i - 1] + 1);
    }
    for (int i = n; i >= 1; i--) {
        if (i == n) a[i] = 0;
        else a[i] = (c[i + 1] >= c[i + 2] ? 1 : a[i + 1] + 1);
    }
    for (int i = 1; i <= n; i++) {
        if (c[i - 1] < c[i + 1] - 1 && i > 0 && i < n)
            ans = max(ans, 1 + b[i] + a[i]);
        else ans = max(ans, 1 + max(b[i], a[i]));
    }
    cout << ans;
    return 0;
}