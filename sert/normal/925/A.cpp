#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1);
const int M = 1e3 + 10;
const int N = 1e6 + 10;

int a[N], b[N];

ll calc(int y1, int x1, int y2, int x2, int v, int n, int cl, int ce) {
    if (x1 > x2) swap(x1, x2);
    if (y1 == y2) {
        return x2 - x1;
    }
    int num = lower_bound(b, b + ce, x1) - b;
    ll ans = INF;
    if (num < ce && b[num] < x2)
        ans = min(ans, (ll)(x2 - x1) + (max(y2, y1) - min(y2, y1) + v - 1) / v);
    else {
        if (num < ce)
            ans = min(ans, (ll)2 * b[num] - x1 - x2 + (max(y2, y1) - min(y2, y1) + v - 1) / v);
        num--;
        if (num >= 0)
            ans = min(ans, -(ll)2 * b[num] + x1 + x2 + (max(y2, y1) - min(y2, y1) + v - 1) / v);
    }
    num = lower_bound(a, a + cl, x1) - a;
    if (num < cl && a[num] < x2)
        ans = min(ans, (ll)(x2 - x1) + (max(y2, y1) - min(y2, y1)));
    else {
        if (num < cl)
            ans = min(ans, (ll)2 * a[num] - x1 - x2 + max(y2, y1) - min(y2, y1));
        num--;
        if (num >= 0)
            ans = min(ans, -(ll)2 * a[num] + x1 + x2 + max(y2, y1) - min(y2, y1));
    }
    assert(ans < INF);
    return ans;
}

int main() {
    //freopen("a.in", "r", stdin);
    int n, m, cl, ce, v;
    scanf("%d %d %d %d %d", &n, &m, &cl, &ce, &v);
    for (int i = 0; i < cl; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < ce; i++) {
        scanf("%d", &b[i]);
    }
    int q;
    scanf("%d", &q);
    int x1, y1, x2, y2;
    for (int i = 0; i < q; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        cout << calc(x1, y1, x2, y2, v, n, cl, ce) << "\n";
    }

}