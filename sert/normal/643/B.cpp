#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e6 + 34;

int a, b, c, d, n, k;
int p[N], len;
string s;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n >> k;
    cin >> a >> b >> c >> d;

    if (n == 4 || k < n + 1) {
        cout << "-1";
        return 0;
    }

    for (int i = 1; i <= n; i++)
        if (i != a && i != b && i != c && i != d)
            p[len++] = i;

    cout << a << " " << d;
    for (int i = 0; i < len; i++) cout << " " << p[i];
    cout << " " << c << " " << b << "\n";

    cout << c << " " << b << " ";
    for (int i = len - 1; i >= 0; i--) cout << p[i] << " ";
    cout << a << " " << d << "\n";

    return 0;
}