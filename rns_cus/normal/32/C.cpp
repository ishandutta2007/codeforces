//C
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, s;

int main(){
    //freopen("c.in", "r", stdin);
    scanf("%d %d %d", &n, &m, &s);
    ll ans = 1ll * ((n - 1) / s + 1) * ((m - 1) / s + 1);
    ll pos = 1ll * ((n - 1) % s + 1) * ((m - 1) % s + 1);
    printf("%I64d\n", ans * pos);
    ///return 9;
}