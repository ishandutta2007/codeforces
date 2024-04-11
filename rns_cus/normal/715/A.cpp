#include <bits/stdc++.h>
using namespace std;
#define N 101000

typedef long long ll;

ll f[N];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = n + 1; i >= 2; i --) {
        f[i] = 1ll * i * (i - 1) * i - (i - 2);
        if(i == 2) f[i] -= 2;
    }
    for(int i = 2; i <= n + 1; i ++) printf("%I64d\n", f[i]);
    puts("");
}