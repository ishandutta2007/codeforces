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

ll c, p;
ll nok(ll a, ll b) {
    p = a * b;
    c = a % b;
    while (c) {
        a = b;
        b = c;
        c = a % b;
    }
    return p / b;
}

ll n, ans, c1, c2, c3;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    //cin >> c1 >> c2;
    //cout << nok(c1, c2); return 0;
    cin >> n;
    if (n == 1) cout << 1;
    if (n == 2) cout << 2;
    if (n == 3) cout << 6;
    if (n == 4) cout << 12;
    if (n < 5) return 0;

    ans = nok(nok(n, n - 1), n - 2);
    //cerr << ans << "\n";
    c1 = nok(n, n - 1);
    c2 = nok(n, n - 2);
    c3 = nok(n - 1, n - 2);
    for (int i = 1; i < n - 2; i++) {
        ans = max(ans, nok(i, c1));
        ans = max(ans, nok(i, c2));
        ans = max(ans, nok(i, c3));
    }

    cout << ans;

    return 0;
}