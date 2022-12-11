#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
const int N = (int)1e6 + 34;
int n, k, ans, a[N];
int main() {
    init();
    char c = 'a';
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < (int)s.length(); i++) {
        ans += min((s[i] - c + 26) % 26, (c - s[i] + 26) % 26);
        c = s[i];
    }
    cout << ans;
    return 0;
}