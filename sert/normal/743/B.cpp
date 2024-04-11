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


int main() {
    //init();

    ll n, k;
    cin >> n >> k;
    k--;

    ll len = (1ll << 52) - 1;
    int num = 52;

    while (true) {
        if (k == len / 2) {
            cout << num;
            return 0;
        }
        num--;
        len /= 2;
        if (k > len)
            k -= len + 1;
    }

    return 0;
}