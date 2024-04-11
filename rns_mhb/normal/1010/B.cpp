#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m, p[40];
    scanf("%d%d", &m, &n);
    for(int i = 1; i <= n; i ++) {
        puts("1");
        fflush(stdout);
        scanf("%d", &p[i]);
        if(p[i] == 0) exit(0);
    }
    int st = 2, ed = m;
    int i = 1;
    while(1) {
        int mid = st + ed >> 1;
        printf("%d\n", mid);
        fflush(stdout);
        int x;
        scanf("%d", &x);
        x *= p[i];
        if(x == 0) exit(0);
        if(x == 1) st = mid + 1;
        else ed = mid - 1;
        i ++;
        if(i > n) i = 1;
    }
}