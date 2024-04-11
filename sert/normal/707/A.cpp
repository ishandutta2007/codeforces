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



int main() {
    init();

    int n, m;
    cin >> n >> m;
    n *= m;
    char ch;
    while (n--) {
        cin >> ch;
        if (ch == 'C' || ch == 'M' || ch == 'Y') {
            cout << "#Color\n";
            return 0;
        }
    }
    cout << "#Black&White\n";

    return 0;
}