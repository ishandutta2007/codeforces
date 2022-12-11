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

int ans, a, b, c, r[N], q, t, md = (1 << 30);

int go(int x) {
    //cerr << x << "\n";
    //if (r[x]) return r[x];
    q = sqrt(x);
    t = (x == q * q ? 1 : 2);
    for (int i = 2; i <= q; i++)
        if (x % i == 0) t += 2;
    return r[x] = t;
}

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> a >> b >> c;
    if (a < c) swap(a, c);
    for (int i = 1; i <= c; i++) for (int j = 1; j <= b; j++) for (int k = i; k <= c; k++)
        ans = (ans + (i == k ? 1 : 2) * go(i * j * k)) % md;
    for (int i = c + 1; i <= a; i++) for (int j = 1; j <= b; j++) for (int k = 1; k <= c; k++)
        ans = (ans + go(i * j * k)) % md;
    cout << ans;

    return 0;
}