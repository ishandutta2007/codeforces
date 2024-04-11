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
const ll INF = 1e12;

ll a[N], b[N];
ll ans = -INF;
int ps;

int main() {
    init();

    int n;
    cin >> n;
    int sum = 0, cur = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    
    if (sum) {
        cout << "YES\n1\n1 " << n << "\n";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cur += a[i];
        if (cur && cur != sum) {
            cout << "YES\n2\n1 " << i + 1 << "\n" << i + 2 << " " << n << "\n";
            return 0;
        }
    }
    cout << "NO\n";

    return 0;
}