#include <cstdio>
#include <cstring>

#define N 5050

typedef long long LL;

int n;
char s[N];
int x[N], y[N];
int pr[N], nx[N];
LL PR[N], NX[N];
LL f[2520][2520];

void init() {
    for(int i = 1; i <= n; i ++) {
        int k;
        LL tp = 1;
        for(k = i - 1; k; k --) {
            if(!y[k]) break;
            tp *= x[k];
        }
        pr[i] = k; PR[i] = tp;
        tp = 1;
        for(k = i + 1; k <= n; k ++) {
            if(!y[k-1]) break;
            tp *= x[k];
        }
        nx[i] = k; NX[i] = tp;
    }
}

int main() {
//    freopen("E.in","r",stdin);
    gets(s);
    int l = strlen(s);
    n = (l + 1) / 2;
    int t = 0;
    for(int i = 1; i <= n; i ++) {
        x[i] = s[t] - '0'; t ++;
        y[i] = s[t] == '*'; t ++;
    }
    init();
    for(int d = 1; d <= n; d ++) {
        for(int i = 1; i + d <= n + 1; i ++) {
            int j = i + d - 1;
            if(i == j) f[i][j] = x[i];
            else {
                if(nx[i] > j) f[i][j] = x[i] * (NX[i] / NX[j]);
                else {
                    f[i][j] = NX[i] * x[i] + f[nx[i]][j];
                }
            }
        }
    }
    LL mx = f[1][n];
    for(int i = 1; i <= n; i ++) for(int j = i; j <= n; j ++) {
        int k;
        LL tp = f[i][j] * PR[i] * NX[j];
        LL tmp = f[1][pr[i]] + f[nx[j]][n] + tp;
        if(mx < tmp) mx = tmp;
    }
    printf("%I64d\n", mx);
    return 0;
}