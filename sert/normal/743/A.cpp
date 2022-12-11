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
    init();

    int n, a, b;
    string s;
    cin >> n >> a >> b >> s;
    cout << (int)(s[a - 1] != s[b - 1]);

    return 0;
}