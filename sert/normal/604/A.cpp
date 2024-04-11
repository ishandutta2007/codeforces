#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t[10], w[10];
int sc, v1, v2;
int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    const int a[5] = {500, 1000, 1500, 2000, 2500};
    for (int i = 0; i < 5; i++) cin >> t[i];
    for (int i = 0; i < 5; i++) cin >> w[i];
    for (int i = 0; i < 5; i++)
        sc += max(a[i] * 3 / 10, a[i] - a[i] * t[i] / 250 - 50 * w[i]);
    cin >> v1 >> v2;
    sc += v1 * 100 - v2 * 50;
    cout << sc;

    return 0;
}