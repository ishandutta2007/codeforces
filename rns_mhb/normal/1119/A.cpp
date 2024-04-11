#include<bits/stdc++.h>
using namespace std;

#define N 300010

int n, a[N];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    int i = 1, j = n;
    while(a[i] == a[n]) i ++;
    while(a[j] == a[1]) j --;
    printf("%d\n", max(j - 1, n - i));
}