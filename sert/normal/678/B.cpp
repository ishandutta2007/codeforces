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
const int N = 63e5 + 34;
const ll INF = 2e9 + 34;

bool is_v(int y) {
    if (y % 400 == 0) return true;
    if (y % 100 == 0) return false;
    return (y % 4 == 0);
}

int main() {
    init();

    int n, d = 0;

    cin >> n;

    for (int i = n + 1; true; i++) {
        if (is_v(i - 1)) d = (d + 2) % 7;
        else d = (d + 1) % 7;

        if (is_v(i) == is_v(n) && d == 0) {
            cout << i;
            return 0;
        }
    }
    return 0;
}