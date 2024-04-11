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

int main() {
    init();

    int x1, y1, x2, y2, x3, y3;
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);

    printf("3\n");
    printf("%d %d\n", x1 + x2 - x3, y1 + y2 - y3);
    printf("%d %d\n", x1 - x2 + x3, y1 - y2 + y3);
    printf("%d %d\n", -x1 + x2 + x3, -y1 + y2 + y3);

    return 0;
}