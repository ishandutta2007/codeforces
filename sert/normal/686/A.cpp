#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.2
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif

    ll n, x, s = 0, c;
    char ch;
    cin >> n >> x;

    while (n--) {
        cin >> ch >> c;
        if (ch == '+')
            x += c;
        else {
            if (c > x)
                s++;
            else
                x -= c;
        }
    }

    cout << x << " " << s << "\n";

    return 0;
}