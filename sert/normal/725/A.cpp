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

int a[N];
int main() {
    init();
    string s;
    int n, p, ans = 0;
    cin >> n >> s;
    p = 0;
    while (p < n && s[p] == '<') p++; ans += p;
    p = n - 1;
    while (p >= 0 && s[p] == '>') p--; ans += n - p - 1;
    cout << ans;
    return 0;
}