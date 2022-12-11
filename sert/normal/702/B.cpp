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

const ll N = 1e6 + 34;
const ll INF = 1e9 + 34;

map <int, int> m;
ll ans;
int a[N];
int n, x;

int main() {
    init();

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        a[i] = x;
        if ((x & (x - 1)) == 0)
            ans--;
        m[x]++;
    }

    for (ll st = 1; st < 2e9; st <<= 1) {
        for (int i = 0; i < n; i++) {
            ans += m[(int)st - a[i]];
        }
    }
    cout << ans / 2;

    return 0;
}