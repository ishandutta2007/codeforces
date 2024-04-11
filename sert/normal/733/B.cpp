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

int l[N], r[N];
int n, df, ans = 1e9;
int num = 0;

int main() {
    init();

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        df += l[i] - r[i];
    }

    ans = abs(df);
    for (int i = 0; i < n; i++) {
        df += 2 * (r[i] - l[i]);
        if (abs(df) > ans) {
            ans = abs(df);
            num = i + 1;
        }
        df -= 2 * (r[i] - l[i]);
    }

    cout << num;

    return 0;
}