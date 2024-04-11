#include<bits/stdc++.h>
using namespace std;

void solve(int l, int r, int h) {
    if(l > r) return;
    if(l == r) {
        for(int i = 2, j = h, sgn = 1; i <= j; sgn ^= 1) {
            if(sgn) printf("%d %d\n", r, j --);
            else printf("%d %d\n", r, i ++);
        }
        return;
    }
    for(int i = 2, j = h, sgn = 1; j; sgn ^= 1) {
        if(sgn) printf("%d %d\n", r, j --);
        else printf("%d %d\n", l, i ++);
    }
    if(l == r-1) return;
    printf("%d %d\n", l+1, 1);
    solve(l+1, r-1, h);
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    puts("1 1");
    if(n == 1 && m == 1) return 0;
    solve(1, n, m);
}