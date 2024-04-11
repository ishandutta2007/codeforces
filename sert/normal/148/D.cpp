#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1e3 + 34;

ld d[N][N];
bool u[N][N];

ld go(int w, int b) {
    if (w <= 0 || b < 0)
        return 0;
    if (u[w][b])
        return d[w][b];
    u[w][b] = true;

    if (b == 0)
        return d[w][b] = 1.0;

    ld res = 0;

    if (w > 0 && b > 1)
        res += (w + 0.0) / (b + w - 2.0) * go(w - 1, b - 2);
    if (b > 2)
        res += (b - 2.0) / (b + w - 2.0) * go(w, b - 3);

    res *= (b + 0.0) / (w + b + 0.0);
    res *= (b - 1.0) / (w + b - 1.0);
    res += (w + 0.0) / (w + b + 0.0);
    return d[w][b] = res;
}

int main() {
    //freopen("a.in", "r", stdin);

    int w, b;
    cin >> w >> b;
    cout.precision(14);
    cout << fixed << go(w, b);

    return 0;
}