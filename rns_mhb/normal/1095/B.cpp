#include<bits/stdc++.h>
using namespace std;

#define N 100010

int n, a[N];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    printf("%d\n", min(a[n] - a[2], a[n-1] - a[1]));
}