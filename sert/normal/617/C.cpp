#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;

long long n, x1, y1, x2, y2, x, y;
ll d1[N], d2[N], ans = 1e18, cur;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n >> x1 >> y1 >> x2 >> y2;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        d1[i] = (x - x1) * (x - x1) + (y - y1) * (y - y1);
        d2[i] = (x - x2) * (x - x2) + (y - y2) * (y - y2);
        cur = max(cur, d2[i]);
    }

    ans = cur;

    for (int i = 0; i < n; i++) {
        cur = 0;
        for (int j = 0; j < n; j++)
            if (d1[j] > d1[i])
                cur = max(cur, d2[j]);
        ans = min(ans, cur + d1[i]);
    }

    cout << ans;


    return 0;
}