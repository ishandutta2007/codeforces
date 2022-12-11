#include <cstdio>
unsigned char k[40][40], ch;
bool u[30], ub[30];
int n, m, x, ans, len;
bool fail, is_s;
int main() {
    scanf("%d%d%d ", &n, &m, &x);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            scanf("%c ", &k[i][j]);
            if (k[i][j] != 'S')
                u[k[i][j] - 'a'] = true;
            else
                is_s = true;
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int ii = 0; ii < n; ii++)
                for (int jj = 0; jj < m; jj++)
                    if (k[ii][jj] == 'S' && (ii - i) * (ii - i) + (jj - j) * (jj - j) <= x * x && k[i][j] != 'S')
                        ub[k[i][j] - 'a'] = true;


    scanf("%d ", &len);
    for (int i = 0; i < len; i++) {
        scanf("%c ", &ch);
        if (ch >= 'a' && ch <= 'z')
            if (!u[ch - 'a'])
                fail = true;
        if (ch >= 'A' && ch <= 'Z') {
            if (!u[ch - 'A'])
                fail = true;
            else {
                if (ub[ch - 'A']) continue;
                if (!is_s) fail = true;
                ans++;
            }

        }
    }
    printf("%d\n", ans * (!fail) - fail);
    return 0;
}