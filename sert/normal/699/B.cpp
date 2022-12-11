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

int n, m, a[N][N], sum;
char ch;
int r[N], c[N];

int main() {
    init();

    scanf("%d %d\n", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            scanf("%c ", &ch);
            a[i][j] = (ch == '*');
            if (a[i][j]) {
                sum++;
                r[i]++;
                c[j]++;
            }
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (sum == r[i] + c[j] - a[i][j]) {
                printf("YES\n%d %d\n", i + 1, j + 1);
                return 0;
            }

    printf("NO\n");
    return 0;
}