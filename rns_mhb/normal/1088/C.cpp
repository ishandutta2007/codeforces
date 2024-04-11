#include<bits/stdc++.h>
using namespace std;

#define N 100010

int n, a[N];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    printf("%d\n", n + 1);
    for(int i = 1; i <= n; i ++) printf("1 %d %d\n", i, N - a[i] + a[i+1]);
    printf("2 %d %d", n, N+1);
}