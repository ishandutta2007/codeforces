#include<bits/stdc++.h>
using namespace std;

int n, d, a[200];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    int x = 0, y = 0;
    for(int i = 1; i <= n; i ++)
        if(a[i] > 0) x ++;
        else if(a[i] < 0) y ++;
    d = 0;
    if(x >= (n + 1) / 2) d = 1;
    else if(y >= (n + 1) / 2) d = -1;
    printf("%d\n", d);
}