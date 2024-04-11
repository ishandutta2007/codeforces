#include<bits/stdc++.h>
using namespace std;

#define N 105

int main(){
    int i, n, a, t[N], b[N], tot = 0;
    scanf("%d %d", &n, &a);
    memset(b, 0, sizeof b);
    for(i = 1; i <= n; i ++) {
        scanf("%d", &t[i]);
        if(t[i]) b[abs(a - i)] ++;
    }
    for(i = 0; i < n; i ++) {
        if(!b[i]) continue;
        if(b[i] == 1) {
            if(i == 0) tot ++;
            else if(a - i > 0 && a + i <= n) continue;
            else tot ++;
         }
        else tot += 2;
    }
    printf("%d\n", tot);
}