#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;
const ll INF = 2e9 + 34;

struct Figure {
    ll x, y;
    char c;

    Figure() {
        x = y = INF;
        c = '@';
    }

    Figure(int xx, int yy, char cc) {
        x = xx;
        y = yy;
        c = cc;
    }

    bool operator < (const Figure &a) const {
        if (c == '@') return false;
        return (a.c == '@' || x * x + y * y < a.x * a.x + a.y * a.y);
    }
};

Figure f[9], t;
int n, x, y, xx, yy, ind;
char c;

int main() {
    init();
    for (int i = 0; i < 8; i++) f[i].c = '@';
    scanf("%d %d %d\n", &n, &x, &y);
    while (n--) {
        scanf("%c %d %d\n", &c, &xx, &yy);
        t = Figure(xx - x, yy - y, c);
        ind = 8;
        if (t.x == 0 && t.y > 0) ind = 0;
        if (t.x == 0 && t.y < 0) ind = 2;
        if (t.y == 0 && t.x > 0) ind = 4;
        if (t.y == 0 && t.x < 0) ind = 6;
        if (t.x == t.y && t.x < 0) ind = 1;
        if (t.x == t.y && t.x > 0) ind = 3;
        if (t.x + t.y == 0 && t.x < 0) ind = 5;
        if (t.x + t.y == 0 && t.x > 0) ind = 7;
        f[ind] = min(f[ind], t);
    }

    for (int i = 0; i < 8; i++) {
        if (i % 2 && (f[i].c == 'B' || f[i].c == 'Q')) {
            cout << "YES\n";
            return 0;
        }
        if (i % 2 == 0 && (f[i].c == 'R' || f[i].c == 'Q')) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";

    return 0;
}