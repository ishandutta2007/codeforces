#include <bits/stdc++.h>

using namespace std;

char A[5010],B[5010];
int N, M;
int f[5010][5010];

int main() {
    scanf("%d%d",&N,&M);
    scanf("%s", A + 1);
    scanf("%s", B + 1);
    int ans = 0;
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=M;j++) {
            f[i][j] = max(f[i - 1][j] - 1, f[i][j - 1] - 1);
            if (A[i] == B[j]) {
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + 2);
                f[i][j] = max(f[i][j], 2);
            }
            ans = max(ans, f[i][j]);
        }
    }
    printf("%d\n",ans);
}