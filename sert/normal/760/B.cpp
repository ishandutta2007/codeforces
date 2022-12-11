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


const ll md = (int)1e9 + 7;
const int N = 5002;

int q[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    //init();

    int n, m, k, l, r, x;
    cin >> n >> m >> k;
    k--;
    l = r = k;
    m -= n;
    x = 1;

    while (true) {
        if (r == n - 1 && l == 0) {
            cout << x + m / n;
            return 0;
        }
        if (r - l + 1 > m) {
            cout << x;
            return 0;
        }
        m -= (r - l + 1);
        r = min(r + 1, n - 1);
        l = max(l - 1, 0);
        x++;
    }


    return 0;
}