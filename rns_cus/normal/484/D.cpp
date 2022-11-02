#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("1.in", "r", stdin);
    int n, v;
    scanf("%d", &n);
    scanf("%d", &v);
    long long a = -v;
    long long b = v;
    long long rlt = 0;
    for(int i = 0; i < n - 1; i ++) {
        scanf("%d", &v);
        if(a < rlt - v) a = rlt - v;
        if(b < rlt + v) b = rlt + v;
        rlt = max(a + v, b - v);
    }
    printf("%I64d\n", rlt);

}