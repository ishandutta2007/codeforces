#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k, i, j;
    scanf("%d%d", &n, &k);
    for(i = 1; i <= n; i ++) {
        for(j = 1; j <= n; j ++) {
            if(j > 1) putchar(' ');
            if(i == j) printf("%d", k);
            else putchar('0');
        }
        puts("");
    }
}