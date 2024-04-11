#include<bits/stdc++.h>
using namespace std;

#define N 55

int n, m, a[N];

int main() {
    scanf("%d", &n);
    m = n >> 1;
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    int x = *min_element(a+1, a+n+1);
    int cnt = 0;
    for(int i = 1; i <= n; i ++) cnt += a[i]==x;
    if(cnt <= m) puts("Alice");
    else puts("Bob");
}