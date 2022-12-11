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

using namespace std;

typedef int ll;
const int N = 1e6 + 7;

ll hy, ay, dy, hm, am, dm, ch, ca, cd, ky, km, kh;
ll ans = 1000000;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> hy >> ay >> dy;
    cin >> hm >> am >> dm;
    cin >> ch >> ca >> cd;

    for (int a = max(ay, dm + 1); a <= 10100; a++)
    for (int d = dy; d <= 10100; d++) {
        km = (hm + a - dm - 1) / (a - dm);
        kh = max(0, 1 + km * (am - d) - hy);
        ans = min(ans, ch * kh + ca * (a - ay) + cd * (d - dy));
    }

    cout << ans;

    return 0;
}