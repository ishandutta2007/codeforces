#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.2
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
const int N = 1e3 + 34;
const int INF = 1e9 + 34;
typedef long long ll;

int x, sum, n;

int main() {
    init();

    scanf("%d", &n);
    if (n == 1)
        sum++;
    while (n--) {
        scanf("%d", &x);
        sum += !x;
    }

    printf(sum == 1 ? "YES" : "NO");

    return 0;
}