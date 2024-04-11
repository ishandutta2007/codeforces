#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 101;
const ll md = 1e9 + 7;

ld r[N][N][N];
ld s[N][N][N];
ld p[N][N][N];

ld rr, ss, pp, sum;
int a, b, c;

int main() {
    //freopen("a.in", "r", stdin);

    cin >> a >> b >> c;
    for (int i = 0; i <= a; i++)
    for (int j = 0; j <= b; j++)
    for (int k = 0; k <= c; k++) {
        if (i * j * k == 0) {
            r[i][j][k] = p[i][j][k] = s[i][j][k] = 0;
            if (i == 0) s[i][j][k] = 1;
            if (j == 0) p[i][j][k] = 1;
            if (p == 0) r[i][j][k] = 1;
            continue;
        }

        rr = i * j;
        ss = j * k;
        pp = k * i;
        sum = rr + ss + pp;
        rr /= sum;
        ss /= sum;
        pp /= sum;

        r[i][j][k] = r[i][j - 1][k] * rr + r[i][j][k - 1] * ss + r[i - 1][j][k] * pp;
        s[i][j][k] = s[i][j - 1][k] * rr + s[i][j][k - 1] * ss + s[i - 1][j][k] * pp;
        p[i][j][k] = p[i][j - 1][k] * rr + p[i][j][k - 1] * ss + p[i - 1][j][k] * pp;

    }

    cout.precision(10);
    cout << fixed << 1.0 - s[a][b][c] - p[a][b][c] << " ";
    cout << fixed << s[a][b][c] << " ";
    cout << fixed << p[a][b][c] << " ";

    return 0;
}