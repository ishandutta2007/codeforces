#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500;

int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}

int n, x[2004], y[2004];
bool u[N][N];
int dx, dy, g;
int xx, yy;
ll ans;


int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    /*for (int i = 0; i < 50; i++)
        for (int j = 0; j < 40; j++)
            cout << 50 + i << " " << 40 + j << "\n";
    return 0;*/

    cin >> n;

    ans = n;
    ans *= n - 1;
    ans *= n - 2;
    ans /= 2;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        u[x[i] + 100][y[i] + 100] = true;
    }

    for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
        dx = abs(x[i] - x[j]);
        dy = abs(y[i] - y[j]);
        g = gcd(dx, dy);
        dx = (x[j] - x[i]) / g;
        dy = (y[j] - y[i]) / g;
        ans++;
        for (xx = x[i] + dx, yy = y[i] + dy; xx >= -100 && yy >= -100 && xx <= 100 && yy <= 100; xx += dx, yy += dy)
            ans -= (int)u[xx + 100][yy + 100];
        for (xx = x[i] - dx, yy = y[i] - dy; xx >= -100 && yy >= -100 && xx <= 100 && yy <= 100; xx -= dx, yy -= dy)
            ans -= (int)u[xx + 100][yy + 100];
    }

    cout << ans / 3;

    return 0;
}