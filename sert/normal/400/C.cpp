#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
const ll N = 134;

ll n, m, x, y, z, p, xx, yy;
ll dx, dy;

void turn1(ll &xq, ll &yq) {
    dx = n - yq - 1;
    dy = xq;
    xq = dx;
    yq = dy;
    swap(n, m);
    return;
}

void turn2(ll &xq, ll &yq) {
    dx = yq;
    dy = m - xq - 1;
    xq = dx;
    yq = dy;
    swap(n, m);
    return;
}

int main() {

    ///freopen("a.in", "r", stdin);

    cin >> n >> m >> x >> y >> z >> p;
    x = x % 4;
    z = z % 4;
    y = y % 2;

    for (int i = 0; i < p; i++) {
        scanf("%I64d%I64d", &yy, &xx);
        xx--;
        yy--;
        for (int j = 0; j < x; j++)
            turn1(xx, yy);
        if (y)
            xx = m - xx - 1;
        for (int j = 0; j < z; j++)
            turn2(xx, yy);
        printf("%I64d %I64d\n", yy + 1, xx + 1);
        if ((x + z) % 2)
            swap(n, m);
    }

    return 0;
}