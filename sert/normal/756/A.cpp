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
int n;
int p[N], b[N];
int sum;
bool u[N];
int c, x;

int main() {
    init();

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", p + i);
        p[i]--;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", b + i);
        sum += b[i];
    }

    for (int i = 0; i < n; i++) {
        if (u[i]) continue;
        u[i] = true;
        c++;
        x = p[i];
        while (x != i) {
            u[x] = true;
            x = p[x];
        }
    }

    if (c == 1) c = 0;
    if (sum % 2 == 0) c++;
    printf("%d\n", c);

    return 0;
}