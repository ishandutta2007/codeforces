#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if(a > b) swap(a, b);
    long long ans = 1ll * a + 1ll * min(b, a + 1) + 2ll * c;
    printf("%I64d\n", ans);
}