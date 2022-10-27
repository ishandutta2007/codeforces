#include <iostream>
#include <cstring>
using namespace std;
const int N = 2002;
typedef long long LL;
const LL MOD = 998244353;

char s[N]; int n;
int pre[N][3];

LL c[N][N];

int main() {
    for (int i = 0; i < N; i ++) c[i][0] = 1;
    for (int i = 1; i < N; i ++) {
        for (int j = 1; j <= i; j ++) {
            c[i][j] = (c[i-1][j] + c[i-1][j-1]) % MOD;
        }
    }

    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i ++) {
        pre[i][0] = pre[i-1][0] + (s[i] == '(' ? 1 : 0);
        pre[i][1] = pre[i-1][1] + (s[i] == ')' ? 1 : 0);
        pre[i][2] = pre[i-1][2] + (s[i] == '?' ? 1 : 0);
    }
    LL ans = 0;
    for (int i = 1; i < n; i ++) {
        int c1 = pre[i][0], c2 = pre[n][1] - pre[i][1];
        int x1 = pre[i][2], x2 = pre[n][2] - pre[i][2];
        for (int j = 0; j <= x1; j ++) {
            int R = c1 + j - c2;
            if (R >= 0 && R <= x2) {
                // printf("i = %d (%d, %d) (%d, %d)\n", i, x1, j, x2, R);
                ans = ans + c[x1][j] * c[x2][R] % MOD * (c1 + j) % MOD;
                ans = (ans % MOD + MOD) % MOD;
            }
        }
    }
    cout << ans << endl;
}