#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 5555;
const int INF = (1 << 30);

int f[N], b[N], a[N];
int n, m, c[N], v[N], base[N];

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int calc(int c) {
    int res = 0;
    for(int i = 1; i <= m; i++) {
        while (c % b[i] == 0) {
            c /= b[i];
            res--;
        }
    }
    
    for(int i = 2; i * i <= c; i++) {
        while (c % i == 0) {
            c /= i;
            res++;
        }
    }
    
    if (c > 1) {
        res++;
    }
    
    return res;
}

int main() {
    scanf("%d %d", &n, &m);
    
    c[0] = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        c[i] = gcd(c[i - 1], a[i]);
    }
    
    for(int i = 1; i <= m; i++) {
        scanf("%d", &b[i]);
    }

    for(int i = 1; i <= n; i++) {
        v[i] = calc(c[i]);
        base[i] = calc(a[i]);
    }
    
    for(int i = 1; i <= n; i++) {
        f[i] = INF;
        for(int j = 0; j < i; j++) {
            f[i] = min(f[i], f[j] + v[i] * (i - j));
        }
    }
    
    int ans = 0, as = 0;
    for(int i = 1; i <= n; i++) {
        as += base[i];
        ans = min(ans, f[i]);
    }
    
    printf("%d\n", as - ans);
    return 0;
}