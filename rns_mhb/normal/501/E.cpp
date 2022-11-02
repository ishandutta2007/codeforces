#include<bits/stdc++.h>
using namespace std;

#define inf 1e9
#define INF 1e18
#define N 100010
typedef long long ll;
template<class T>inline void chkmin(T&x,T y){if(y<x)x=y;}
template<class T>inline void chkmax(T&x,T y){if(x<y)x=y;}

int a[N], b[N], c[N], d[N];

int main() {
    int n, i, fl = 0, m = 0;
    scanf("%d", &n);
    for(i = 1, a[0] = 1; i <= n; i ++) scanf("%d", a + i);
    for(i = 1; a[i] == a[n - i + 1]; i ++);
    if(i > n) {printf("%I64d\n", 1ll * n * (n + 1) / 2); return 0;}
    int mid = n + 1 >> 1;
    int l = i, r = n + 1 - i;
    for(i = l; i <= r; i ++) b[a[i]] ++, d[a[i]] ++;
    for(i = 0; i < N; i ++) if(b[i] & 1) fl ++;
    if(fl > 1) {puts("0"); return 0;}
    for(i = r;; i --) {
        if(i > mid) {
            c[a[i]] ++;
            b[a[i]] --;
            if(b[a[i]] < c[a[i]]) break;
            m ++;
        }
        if(i <= mid) {
            if(n & 1 && i == mid) b[a[i]] --;
            if(b[a[i]] < c[a[i]]) break;
            if(a[i] != a[n + 1 - i]) break;
            m ++;
        }
    }
    memset(c, 0, sizeof c);
    mid = n + 2 >> 1;
    for(i = l;; i ++) {
        if(i < mid) {
            c[a[i]] ++;
            d[a[i]] --;
            if(d[a[i]] < c[a[i]]) break;
            m ++;
        }
        if(i >= mid) {
            if(n & 1 && i == mid) d[a[i]] --;
            if(d[a[i]] < c[a[i]]) break;
            if(a[i] != a[n + 1 - i]) break;
            m ++;
        }
    }
    printf("%I64d\n", 1ll * (m + l) * l);
}