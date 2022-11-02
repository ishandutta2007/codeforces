#include<bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

#define N 300010
#define M 20

int a[N], L[N][M], R[N][M], X[N][M], Y[N][M];

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i ++) {
        for(int j = 0; j < M; j ++) L[i][j] = L[i-1][j];
        for(int j = 0; j < M; j ++) if(a[i] >> j & 1) L[i][j] = i;
    }
    for(int i = 0; i < M; i ++) R[n+1][i] = n + 1;
    for(int i = n; i; i --) {
        for(int j = 0; j < M; j ++) R[i][j] = R[i+1][j];
        for(int j = 0; j < M; j ++) if(a[i] >> j & 1) R[i][j] = i;
    }
    for(int i = 0; i < M; i ++) Y[n+1][i] = n + 1;
    for(int i = n; i; i --) {
        for(int j = 0; j < M; j ++) Y[i][j] = n + 1;
        for(int j = 0; j < M; j ++) if(a[i] >> j & 1) {
            int ii = R[i+1][j];
            for(int h = 0; h < M; h ++) if(Y[ii][h] < Y[i][h]) Y[i][h] = Y[ii][h];
            Y[i][j] = i;
        }
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = 0; j < M; j ++) if(a[i] >> j & 1) {
            int ii = L[i-1][j];
            for(int h = 0; h < M; h ++) if(X[ii][h] > X[i][h]) X[i][h] = X[ii][h];
            X[i][j] = i;
        }
    }
    while(q --) {
        int x, y;
        scanf("%d%d", &x, &y);
        bool flag = 0;
        for(int i = 0; i < M; i ++) {
            int xx = Y[x][i], yy = X[y][i];
            if(xx <= yy) {
                flag = 1;
                break;
            }
        }
        if(flag) puts("Shi");
        else puts("Fou");
    }
}