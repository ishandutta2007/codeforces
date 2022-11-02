#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y, cnt = 0;
    scanf("%d%d%d", &n, &x, &y);
    for(int i = 0, m; i < n; i ++) {
        scanf("%d", &m);
        if(m <= x) cnt ++;
    }
    if(x > y) printf("%d\n", n);
    else printf("%d\n", (cnt + 1) / 2);
}