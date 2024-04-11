#include <bits/stdc++.h>
using namespace std;

int id[10000001];

int main() {
    //freopen("2.in", "r", stdin);
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i ++) scanf("%d", &id[i]);
    int x = 1;
    while(1) {
        if(k <= x) break;
        k -= x;
        x ++;
    }
    printf("%d\n", id[k]);
}