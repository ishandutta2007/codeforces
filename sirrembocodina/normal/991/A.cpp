#include <iostream>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

int d[60][60][2];
int g[60][60][2];
int a[60], b[60], c[60];
long long s[60];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    int d = n - a - b + c;
    if (a > n || b > n || c > a || c > b || d < 1) {
        cout << -1 << endl;
        return 0;
    }
    cout << d << endl;
    return 0;
}