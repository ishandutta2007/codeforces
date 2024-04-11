#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

LL solve(LL p, LL x) {
    return (p + x - 1) / x * x;
}

int main() {
    int T;
    LL p,a,b,c;
    scanf("%d",&T);
    while(T--) {
        scanf("%lld%lld%lld%lld",&p,&a,&b,&c);
        LL ans = 3e18;
        ans = min(ans, solve(p, a));
        ans = min(ans, solve(p, b));
        ans = min(ans, solve(p, c));
        ans -= p;
        printf("%lld\n",ans);
    }
}