#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n, m;
char s[110][110];
char ans[110][110];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&m);
        for (int i = 1; i <= n; i++) {
            scanf("%s", s[i] + 1);
        }

        bool ok;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if ((i + j) % 2 == 1) {
                    ans[i][j] = 'R';
                } else {
                    ans[i][j] = 'W';
                }
            }
            ans[i][m + 1] = 0;
        }
        ok = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i][j] != '.' && s[i][j] != ans[i][j]) ok = false;
            }
        }
        if (ok) {
            puts("YES");
            for (int i = 1; i <= n; i++) {
                printf("%s\n",ans[i] + 1);
            }
            continue;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if ((i + j) % 2 == 1) {
                    ans[i][j] = 'W';
                } else {
                    ans[i][j] = 'R';
                }
            }
            ans[i][m + 1] = 0;
        }
        ok = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i][j] != '.' && s[i][j] != ans[i][j]) ok = false;
            }
            ans[i][m + 1] = 0;
        }
        if (ok) {
            puts("YES");
            for (int i = 1; i <= n; i++) {
                printf("%s\n",ans[i] + 1);
            }
            continue;
        }

        puts("NO");
    }    
}