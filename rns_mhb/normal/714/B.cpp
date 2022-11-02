#include<bits/stdc++.h>
using namespace std;

int a[100010];

int main() {
    int n, i;
    scanf("%d", &n);
    for(i = 0; i < n; i ++) scanf("%d", a + i);
    sort(a, a + n);
    n = unique(a, a + n) - a;
    if(n > 3) puts("NO");
    if(n < 3) puts("YES");
    if(n == 3) {
        if(a[2] - a[1] == a[1] - a[0]) puts("YES");
        else puts("NO");
    }
}