#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.2
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
const int N = 1e6 + 34;
const int INF = 1e9 + 34;
typedef long long ll;

int ans = N, n, a[N], b[N];
string s[N];
bool fail;

int main() {
    init();

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        a[i] = (1 << (s[i][1] - '1'));
        if (s[i][0] == 'B') a[i] |= (1 << 5);
        if (s[i][0] == 'G') a[i] |= (1 << 6);
        if (s[i][0] == 'R') a[i] |= (1 << 7);
        if (s[i][0] == 'Y') a[i] |= (1 << 8);
        if (s[i][0] == 'W') a[i] |= (1 << 9);
    }

    for (int msk = 0; msk < (1 << 10); msk++) {
        for (int i = 0; i < n; i++)
            b[i] = msk & a[i];
        fail = false;
        for (int i = 0; i < n && !fail; i++)
            for (int j = i + 1; j < n && !fail; j++)
                if (b[i] == b[j] && s[i] != s[j])
                    fail = true;
        if (!fail)
            ans = min(ans, __builtin_popcount(msk));
    }

    cout << ans;

    return 0;
}