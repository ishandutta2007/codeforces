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

int a[N], n, ans = INF;
char s[N];

int main() {
    init();

    scanf("%d%s", &n, s);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);

    for (int i = 1; i < n; i++)
        if (s[i - 1] == 'R' && s[i] == 'L')
            ans = min(ans, a[i] - a[i - 1]);

    printf("%d", (ans == INF ? -1 : ans / 2));

    return 0;
}