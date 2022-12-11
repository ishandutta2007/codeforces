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

const int N = (int)1e6 + 34;

int bro[N];
ll sum[N];
ll ans = 0;
vector <ll> v;
bool u[N];
int n, x;
int a[N], p[N], t;

int main() {
    init();
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> p[i];

    for (int i = n - 1; i >= 0; i--) {
        v.push_back(ans);
        x = p[i] - 1;
        u[x] = true;
        bro[x] = t = x;
        sum[x] = a[x];
        if (x > 0 && u[x - 1]) {
            bro[x] = bro[x - 1];
            bro[bro[x - 1]] = x;
            sum[bro[x]] += a[x];
            t = bro[x];
        }

        if (u[x + 1]) {
            t = bro[x];
            bro[bro[x]] = bro[x + 1];
            bro[bro[x + 1]] = t;
            sum[t] += sum[x + 1];
        }

        ans = max(ans, sum[t]);
    }

    for (int i = n - 1; i >= 0; i--)
        cout << v[i] << "\n";

    return 0;
}