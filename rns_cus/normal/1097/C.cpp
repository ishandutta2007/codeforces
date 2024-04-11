#include <bits/stdc++.h>
using namespace std;

#define N 500100

int n, a[N], b[N], fi[N];
char s[N];

int main() {
    scanf("%d", &n);
    int rlt = 0, cnt = 0;
    for (int i = 0; i < n; i ++) {
        scanf("%s", s + 1);
        int len = strlen(s + 1);
        fi[0] = 0;
        int mn = 0;
        for (int j = 1; j <= len; j ++) {
            fi[j] = fi[j-1];
            if (s[j] == '(') fi[j] ++;
            else fi[j] --;
            mn = min(mn, fi[j]);
        }
        if (mn < 0 && mn < fi[len]) continue;
        if (fi[len] > 0) a[fi[len]] ++;
        else if (fi[len] < 0) b[-fi[len]] ++;
        else cnt ++;
    }
    for (int i = 1; i < N; i ++) rlt += min(a[i], b[i]);
    rlt += cnt / 2;
    printf("%d\n", rlt);
}