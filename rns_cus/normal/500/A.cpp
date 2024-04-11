#include <bits/stdc++.h>
using namespace std;

int a[1000001];

int main() {
    int n, p;
    scanf("%d %d", &n, &p);
    for(int i = 1; i < n; i ++) scanf("%d", &a[i]);
    int s = 1;
    while(s < p) s += a[s];
    if(s == p) puts("YES");
    else puts("NO");
}