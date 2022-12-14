#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ != 4 && __GNUC_MINOR__ != 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = (int)1e6 + 34;
const ll INF = 1e9 + 34;

int main() {
    //init();
    //freopen("a.in", "r", stdin);
    int n, b = 0, d, t;
    int max2 = -INF;
    int min1 = INF;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &d, &t);
        if (t == 1)
            min1 = min(min1, b);
        else
            max2 = max(max2, b);
        b += d;
    }

    if (max2 == -INF)
        cout << "Infinity";
    else if (min1 <= max2)
        cout << "Impossible";
    else
        cout << 1899 + b - max2;

    return 0;
}