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
const int INF = 1e9 + 34;

int n, k;
int a[N];

int main() {
    init();

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    k = (n - 1) / 2;
    nth_element(a, a + k, a + n);
    printf("%d", a[k]);


    return 0;
}