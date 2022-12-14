#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[100], s[50001];
    int len = 0;
    for(int i = 1; i <= 1000; i ++) {
        int x = i;
        int cnt = 0;
        while(x) {
            a[cnt++] = x % 10;
            x /= 10;
        }
        for(int j = cnt-1; j >= 0; j --) s[len++] = a[j];
    }
    int n;
    scanf("%d", &n);
    printf("%d\n", s[n-1]);
}