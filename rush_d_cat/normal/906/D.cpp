#include <iostream>
using namespace std;
typedef long long LL;
const int N = 100000+10;

LL mpow(LL a, LL n, LL M) {
    if (n == 0) return 1;
    LL t = mpow(a, n/2, M);
    if (n % 2) return t*t%M*a%M;
    return t*t%M;
}

LL getphi(LL x) {
    LL ans = x;
    for (LL i = 2; i * i <= x; i ++) {
        if (x % i == 0) {
            ans = ans * (i - 1) / i;
            while (x % i == 0) x /= i;
        }
    }
    if (x > 1) ans = ans * (x - 1) / x;
    return ans;
}

LL phi[1002];
int n, m;
int w[N], q, l, r;
int lim, cur;
LL mode(LL x, LL y) {
    if (x < y) return x;
    return x%y+y;
}

LL cac(int l, int r, int dep) {
    //if (l > r || dep == lim) return 1;
    if (l == r) return w[l];
    if (dep == lim) return 1;
    LL t = cac(l+1, r, dep+1);
    LL ans = 1, x = w[l];
    while (t) {
        if (t&1) ans = mode(ans*x, phi[dep]);
        x=mode(x*x, phi[dep]); t >>= 1;
    }
    //printf("%lld %lld %lld %lld\n", l,r,dep,ans);
    return ans;
}

int main() {    
    scanf("%d %d", &n, &m);

    lim = 0, cur = m;
    phi[0] = m;
    while (m > 1) {
        phi[++lim] = m = getphi(m);
    }

    for (int i = 1; i <= n; i ++) {
        scanf("%d", &w[i]);
    }
    
    scanf("%d", &q);

    while (q --) {
        scanf("%d %d", &l, &r);
        printf("%lld\n", cac(l, r, 0) % phi[0]);
    }
    
}