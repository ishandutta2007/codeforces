#include<bits/stdc++.h>
using namespace std;

int a[1111];

bool good(int n) {
    for(int i = 1; i < n; i ++) if(a[i] > a[i+1]) return 0;
    for(int i = 1; i <= n; i ++) if(a[i] == 0) return 0;
    return 1;
}

int main() {
    int n, m, c;
    scanf("%d%d%d", &n, &m, &c);
    while(m --) {
        int x;
        scanf("%d", &x);
        if(x <= c/2) {
            int y = 1;
            while(y < n && a[y] && a[y] <= x) y ++;
            a[y] = x;
            printf("%d\n", y);
            fflush(stdout);
        }
        else {
            int y = n;
            while(y > 1 && a[y] >= x) y --;
            a[y] = x;
            printf("%d\n", y);
            fflush(stdout);
        }
        if(good(n)) return 0;
    }
}