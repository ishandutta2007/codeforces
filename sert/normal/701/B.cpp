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

int x, y, k;
ll n, m;
bool ux[N], uy[N];

int main() {
    init();

    cin >> n >> k;
    m = n;
    while (k--) {
        cin >> x >> y;
        if (!ux[x]) m--;
        ux[x] = true;
        if (!uy[y]) n--;
        uy[y] = true;
        cout << n * m << "\n";
    }

    return 0;
}