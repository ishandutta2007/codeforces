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
const ld EPS = 1e-12;
const ll md = (int)1e9 + 7;
const ll o_10e6 = 397802501;

const int N = (int)1e6 + 34;
ll f[N], o[N];

bool ok(int x, int a, int b) {
    if (x == 0) return false;
    while (x) {
        if (x % 10 != a && x % 10 != b) return false;
        x /= 10;
    }
    return true;
}

int main() {
    init();

    ll a00, a01, a10, a11;
    cin >> a00 >> a01 >> a10 >> a11;

    if (a00 + a01 + a10 + a11 == 0) {
        cout << "1";
        return 0;
    }

    string s;

    ll a0 = sqrt(a00 * 2) + 1;
    ll a1 = sqrt(a11 * 2) + 1;

    if (a00 + a01 + a10 + a11 == a00 && a0 * (a0 - 1) == a00 * 2) {
        for (int i = 0; i < a0; i++) s.push_back('0');
        cout << s;
        return 0;
    }

    if (a00 + a01 + a10 + a11 == a11 && a1 * (a1 - 1) == a11 * 2) {
        for (int i = 0; i < a1; i++) s.push_back('1');
        cout << s;
        return 0;
    }

    if (a0 * (a0 - 1) != a00 * 2 || a1 * (a1 - 1) != a11 * 2 || a1 * a0 != a10 + a01) {
        cout << "Impossible";
        return 0;
    }

    ll z = a10 / a0;
    ll o = a10 % a0;

    for (int i = 0; i < z; i++) s.push_back('1');
    for (int i = o; i < a0; i++) s.push_back('0');
    if (z < a1) s.push_back('1');
    for (int i = 0; i < o; i++) s.push_back('0');
    for (int i = z + 1; i < a1; i++) s.push_back('1');

    cout << s;

    return 0;
}