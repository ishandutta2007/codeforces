#include <bits/stdc++.h>

using namespace std;

int const F = 1234;

int ans[F * F];

vector<int> z[F][F];
int x[F * F], y[F * F];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", x + i, y + i);
        z[x[i] / F][y[i] / F].push_back(i);
    }
    int ac = 0;
    for (int i = 0; i < F; i++) {
        if ((i & 1) == 0) {
            for (int j = F - 1; j >= 0; j--) {
                for (int k : z[i][j]) ans[ac++] = k;
            }
        } else {
            for (int j = 0; j < F; j++) {
                for (int k : z[i][j]) ans[ac++] = k;
            }        
        }
    }
    for (int i = 0; i < ac; i++) {
        if (i > 0) putchar(' ');
        printf("%d", 1 + ans[i]);
    }
    puts("");
}