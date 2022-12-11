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

bool u, d, l, r;
int ans = 1;

int main() {
    init();

    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        if ((s[i] == 'R' && l) || (s[i] == 'L' && r) || (s[i] == 'D' && u) || (s[i] == 'U' && d)) {
            ans++;
            l = r = u = d = false;
        }
        if (s[i] == 'R') r = true;
        if (s[i] == 'L') l = true;
        if (s[i] == 'U') u = true;
        if (s[i] == 'D') d = true;
    }

    cout << ans;

    return 0;
}