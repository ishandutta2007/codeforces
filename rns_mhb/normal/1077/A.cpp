#include<bits/stdc++.h>
using namespace std;

int main() {
    int t, a, b, k;
    scanf("%d", &t);
    while(t --) {
        scanf("%d%d%d", &a, &b, &k);
        if(k & 1) printf("%I64d\n", a + 1ll*(a-b)*(k/2));
        else printf("%I64d\n", 1ll * (a-b) * (k/2));
    }
}