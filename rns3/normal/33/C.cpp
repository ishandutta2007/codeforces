#include <bits/stdc++.h>
using namespace std;
#define M 100100
const int oo = 1000000;
int ABS(int u) {return u > 0 ? u : - u;}

int n;
int a[M];
int s[M];
int rlt;

int main() {
    //freopen("C3.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        s[i] = s[i-1] + a[i];
        rlt = max(rlt, ABS(s[i]));
        //printf("%d ", a[i]);
    }
    //puts("");

    int t = 0;
    for (int i = 1; i <= n; i++) {
        t = min(t, s[i]);
        int hu = ABS(s[n] - s[i]);
        rlt = max(rlt, s[i] - 2 * t + hu);
    }
    printf("%d\n", rlt);
    return 0;
}