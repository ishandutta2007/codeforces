#include <bits/stdc++.h>
using namespace std;

int main() {

#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.2
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif

    string s;
    cin >> s;
    cout << s;
    reverse(s.begin(), s.end());
    cout << s;

    return 0;
}