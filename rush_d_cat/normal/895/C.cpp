#include <iostream>
using namespace std;
const int M = 1000000007;
const int N = 100000+10;
typedef long long LL;

int a[N], n;
int d[33];

int notprime[102], prime[102];

void init() {
    for (int i = 2; i < 100; i ++) {
        if (notprime[i]) continue;
        prime[++prime[0]] = i;
        for (int j = 2 * i; j < 100; j += i) {
            notprime[j] = 1;
        }
    }
}

LL mpow(LL a, LL x) {
    if (x == 0) return 1;
    LL t = mpow(a, x / 2);
    if (x % 2) 
        return t * t % M * a % M;
    return t * t % M; 
}

void ins(int c) { 
    int x = 0;
    for (int i = 1; i <= prime[0]; i ++) { 
        int p = c, q = 0;  
        while (p % prime[i] == 0) {  
            p /= prime[i]; 
            q ++; 
        } 
        if (q % 2) x += (1 << (i - 1)); 
    }
    for (int i=20;i>=0;i--) if ((x>>i)&1) {
        if (d[i]) {
            x ^= d[i];
        } else {
            d[i] = x;
            break;
        }
    }
}

int main() {
    init();    
    scanf("%d", &n);
    for (int i=1;i<=n;i++) {
        scanf("%d", &a[i]);
        ins(a[i]);
    }
    int size = 0;
    for (int i = 0; i <= 20; i ++) {
        if (d[i]) size ++;
    }
    LL ans = mpow(2, n - size) - 1;
    printf("%lld\n", ans);
}