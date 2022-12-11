#include <bits/stdc++.h>
using namespace std;

#define scanf(a, b) assert(scanf(a, b) != -1)
#define TASKNAME "cactus"
void init() {
#if __gnu_linux__ == 1
    assert(freopen("a.in", "r", stdin));
    //freopen("a.out", "w", stdout);
#else
    //freopen(TASKNAME".in", "r", stdin);
    //freopen(TASKNAME".out", "w", stdout);
#endif
}

typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
const ll INF = (ll)1e18 + 34;
const ll md = (ll)1e9 + 7;

int n, x[N], y[N];
ll sumx, sumy, sum2x, sum2y;

int main() {
    init();

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", x + i);
        scanf("%d", y + i);
        sumx += x[i];
        sumy += y[i];
        sum2x += (ll)x[i] * (ll)x[i];
        sum2y += (ll)y[i] * (ll)y[i];
    }

    cout << (n == 1 ? 0 : (sum2x + sum2y) * n - sumx * sumx - sumy * sumy);

    return 0;
}