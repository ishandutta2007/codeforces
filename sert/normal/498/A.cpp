#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>

#define ff first
#define ss second
#define y1 yy1

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

ll sgn(ll x) {
    return (x > 0 ? 1 : -1);
}

ll x1, y1, x2, y2, a, b, c, cnt, n;
ll r1, r2;

int main() {
    //freopen("a.in", "r", stdin);
   // freopen("a.out", "w", stdout);

    cin >> x1 >> y1 >> x2 >> y2;

    cin >> n;
    while (n--) {
        cin >> a >> b >> c;
        r1 = sgn(x1 * a + y1 * b + c);
        r2 = sgn(x2 * a + y2 * b + c);
        if (r1 != r2) cnt++;
    }
    cout << cnt;
    return 0;
}