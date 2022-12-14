#include <bits/stdc++.h>
using namespace std;
#define M 2001001
const int mod = 1000000007;

int n, m;
char s[M];
int last[M];
int f[M];

int main() {
    ///freopen("E1.in", "r", stdin);
    scanf("%d %d", &n, &m);

    scanf("%s", s + 1);
    int len = strlen(s + 1);
    f[0] = 1;
    for (int i = 1; i <= len; i++) {
        int c = s[i] - 'a';
        f[i] = f[i-1] * 2 % mod;
        if (last[c]) {
            f[i] = (f[i] - f[last[c]-1] + mod) % mod;
        }
        last[c] = i;
        //printf("f[%d] = %d\n", i, f[i]);
    }

    for (int i = len + 1; i <= len + n; i++) {
        int c = 0;
        for (int j = 1; j < m; j++) {
            if (last[j] < last[c]) {
                c = j;
            }
        }
        f[i] = f[i-1] * 2 % mod;
        if (last[c]) {
            f[i] = (f[i] - f[last[c]-1] + mod) % mod;
        }
        last[c] = i;
    }
    printf("%d\n", f[len + n]);
    return 0;
}