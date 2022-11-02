#include<bits/stdc++.h>
using namespace std;

#define N 1010

int n;
double p[N][N], a[N], b[N], d[N];
bool vis[N];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) for(int j = 1; j <= n; j ++) scanf("%lf", p[i] + j), p[i][j] /= 100;
    for(int i = 1; i <= n; i ++) d[i] = 1e9, a[i] = b[i] = 1;
    d[n] = 0;
    for(int i = 1; i <= n; i ++) {
        double mn = 1e9;
        int x;
        for(int j = 1; j <= n; j ++) if(!vis[j] && d[j] < mn) {
            mn = d[j];
            x = j;
        }
        vis[x] = 1;
        for(int y = 1; y <= n; y ++) if(!vis[y]) {
            b[y] += p[y][x]  * a[y] * d[x];
            a[y] *= 1 - p[y][x];
            d[y] = b[y] / (1 - a[y]);
        }
    }
    printf("%.7lf\n", d[1]);
}