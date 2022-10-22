#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int MOD = 998244353;

char s[1010], t[1010];
int n, m;
int f[1010][1010][2];

void upd(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

int main() {
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    n = strlen(s + 1);
    m = strlen(t + 1);
    memset(f, 0, sizeof(f));
    for (int i=1;i<=m;i++) {
        f[0][i][1] = 1;
        if (i > 0 && t[i] != t[i - 1]) upd(f[0][i][1], f[0][i - 1][1]);
    }
    for (int i=1;i<=n;i++) {
        f[i][0][0] = 1;
        if (i > 0 && s[i] != s[i - 1]) upd(f[i][0][0], f[i - 1][0][0]);
    }
    int ans = 0;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            // push i
            f[i][j][0] = 0;
            if (s[i] != t[j]) {
                upd(f[i][j][0], f[0][j][1]);
                if (i > 1) upd(f[i][j][0], f[i - 1][j][1]);
            }
            if (s[i] != s[i - 1] && i > 1) {
                upd(f[i][j][0], f[i - 1][j][0]);
            }
            // push j
            if (s[i] != t[j]) {
                upd(f[i][j][1], f[i][0][0]);
                if (j > 1) upd(f[i][j][1], f[i][j - 1][0]);
            }
            if (t[j] != t[j - 1] && j > 1) {
                upd(f[i][j][1], f[i][j - 1][1]);
            }
            upd(ans, f[i][j][0]);
            upd(ans, f[i][j][1]);
        }
    }
    printf("%d\n",ans);
}