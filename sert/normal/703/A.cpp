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

int n, a, b, m, c;

int main() {
    //init();
    cin >> n;
    while (n--) {
        cin >> a >> b;
        if (a > b) m++;
        if (a < b) c++;
    }

    if (m > c) cout << "Mishka";
    if (m < c) cout << "Chris";
    if (m == c) cout << "Friendship is magic!^^";


    return 0;
}