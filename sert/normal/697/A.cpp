#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.2
    //freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif

    int t, s, x;
    cin >> t >> s >> x;

    cout << ((x == t || (x > t + 1 && (x - t) % s < 2)) ? "YES" : "NO");

    return 0;
}