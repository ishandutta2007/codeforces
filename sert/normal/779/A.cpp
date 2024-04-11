#include <bits/stdc++.h>
using namespace std;
#define TASKNAME "sum"
void init() {
#ifdef MOI_KOD_IDEALEN
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#else
    //freopen(TASKNAME".in", "r", stdin);
    //freopen(TASKNAME".out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = 1e6 + 34;
const ll md = (ll)1e9 + 7;

int n, x, ans, a[N], b[N];

int main() {
    init();

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a[x]++;
    }
    for (int i = 0; i < n; i++) {
        cin >> x;
        b[x]++;
    }

    for (int i = 1; i <= 5; i++) {
        if ((a[i] & 1) != (b[i] & 1)) {
            cout << "-1";
            return 0;
        }
        ans += abs(a[i] - b[i]) / 2;
    }

    cout << ans / 2;

    return 0;
}