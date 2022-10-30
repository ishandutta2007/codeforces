//coded by du
#include <bits/stdc++.h>
using namespace std;
#define N 201000
#define M 52
#define NN 30
double f[N][M];
long long sum[N];
double Sum1[N];
int t[N];
int A[N];
#define inf 1e18

double Doit(int i, int k, int j) {
    return f[k][j - 1] + f[i][1] - f[k][1] - (Sum1[i] - Sum1[k]) * sum[k];
}
int g[N][M];
double G[N];
double Ca(int x, int y) {
    return 1.0 * (G[y] - G[x]) / (sum[y] - sum[x]);
}
int val[N];
int main() {
    //freopen("2.in", "r", stdin);
    //freopen("out1.txt", "w", stdout);
    int n, K;
    scanf("%d%d", &n, &K);
    for(int i = 1; i <= n; i ++) scanf("%d", &t[i]);
    for(int i = 1; i <= n; i ++) for(int j = 1; j <= K; j ++) f[i][j] = inf;
    f[1][1] = 1.0;
    sum[1] = t[1];
    Sum1[1] = 1.0 / t[1];
    for(int i = 2; i <= n; i ++) {
        sum[i] = sum[i - 1] + t[i];
        Sum1[i] = Sum1[i - 1] + 1.0 / t[i];
        f[i][1] = f[i - 1][1] + 1.0 * sum[i] / t[i];
    }
    for(int i = 2; i <= K; i ++) {
        for(int j = i - 1; j <= n; j ++) G[j] = f[j][i - 1] - f[j][1] + Sum1[j] * sum[j];
        //for(int j = i - 1; j <= n; j ++) printf("%d %lf\n", j, G[j]);
        int st = 0;
        int en = 0;
        f[i][i] = 1.0 * i;
        A[en ++] = i - 1;
        for(int j = i + 1; j <= n; j ++) {
            while(en - 1 > st) {
                if(Ca(A[en - 1], A[en - 2]) > Ca(j - 1, A[en - 1])) en --;
                else break;
            }
            A[en ++] = j - 1;
            //printf("%d\n", en);
            while(st < en - 1) {
                if(Ca(A[st + 1], A[st]) < Sum1[j]) st ++;
                else break;
            }
            f[j][i] = G[A[st]] - Sum1[j] * sum[A[st]] + f[j][1];

        }
    }
    printf("%.8lf\n", f[n][K]);
    return 0;
}