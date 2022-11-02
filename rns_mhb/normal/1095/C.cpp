#include<bits/stdc++.h>
using namespace std;

#define N 100010

int good(int n, int k) {
    return k <= n && k >= __builtin_popcount(n);
}

void make(int n, int k) {
    if(k == 0) return;
    int x = 1;
    while(1) {
        if(good(n-x, k-1)) {
            printf("%d ", x);
            make(n-x, k-1);
            return;
        }
        x <<= 1;
    }
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    if(!good(n, k)) {
        puts("NO");
        return 0;
    }
    puts("YES");
    make(n, k);
    puts("");
}