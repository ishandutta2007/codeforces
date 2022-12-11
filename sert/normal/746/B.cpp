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
    int n;
    string s;
    cin >> n >> s;

    if (n % 2 == 1) {
        for (int i = n - 1 - n % 2; i >= 0; i -= 2) cout << s[i];
        for (int i = 0; i < n; i+=2) cout << s[i];
    } else {
        for (int i = n - 1 - (n+1) % 2; i >= 0; i -= 2) cout << s[i];
        for (int i = 1; i < n; i+=2) cout << s[i];
    }

    return 0;
}