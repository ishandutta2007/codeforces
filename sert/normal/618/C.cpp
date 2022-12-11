#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 34;

struct pt {
    ll x, y;
    int n;
    pt() {}
    pt(ll xx, ll yy, int nn = -1) {
        x = xx;
        y = yy;
        n = nn;
    }
    pt operator - (const pt &a) const {
        return pt(x - a.x, y - a.y);
    }
    ll operator % (const pt &a) const {
        return x * a.y - y * a.x;
    }
    bool operator < (const pt &a) const {
        return (x * a.y - y * a.x ? x * a.y - y * a.x > 0 : x * x + y * y < a.x * a.x + a.y * a.y);
    }
};
pt a[N], nn;
int x, y, n, num = 0;
int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x, &y);
        a[i] = pt(x, y, i + 1);
    }
    nn = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i].x < nn.x || (a[i].x == nn.x && a[i].y < nn.y)) {
            nn = a[i];
            num = i;
        }
    }
    for (int i = 0; i < n; i++) {
        a[i].x -= nn.x;
        a[i].y -= nn.y;
    }

    swap(a[0], a[num]);
    sort(a + 1, a + n);

    num = 2;
    while ((a[num] - a[0]) % (a[1] - a[0]) == 0)
        num++;

    cout << a[0].n << " " << a[1].n << " " << a[num].n << "\n";

    return 0;
}