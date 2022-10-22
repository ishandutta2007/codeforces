#include <bits/stdc++.h>
using namespace std;
const int N = 300005;

int n , a[N] , s[N];
int nxt[60][N] , pp[2][N];

int main() {
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i) {
        long long x;
        scanf("%lld" , &x);
        a[i] = __builtin_popcountll(x);
        s[i + 1] = s[i] + a[i]; 
    }
    for (int i = 0 ; i <= n ; ++ i) {
        pp[0][i + 1] = pp[0][i] + (~s[i] & 1);
        pp[1][i + 1] = pp[1][i] + (s[i] & 1);
    }
    for (int k = 0 ; k < 60 ; ++ k) {
        nxt[k][n] = n;
        for (int i = n - 1 ; i >= 0 ; -- i) {
            if (a[i] > k) {
                nxt[k][i] = i;
            } else {
                nxt[k][i] = nxt[k][i + 1];
            }
        }
    }

    long long res = 0;
    for (int i = 0 ; i < n ; ++ i) {
        int x = i , mx = a[i];
        while (x < n) {
            int p = nxt[mx][x];
            // j + 1 belongs to [x + 1 , p]
            int l = x + 1 , r = p;
            // 2mx <= s[j + 1] - s[i];
            // s[j + 1] >= s[i] + 2mx
            int q = (lower_bound(s , s + n + 1 , 2 * mx + s[i]) - s);
            l = max(l , q);
            if (l <= r) {
                int o = s[i] & 1;
                res += pp[o][r + 1] - pp[o][l];
            }
            x = p , mx = a[x];
        }
    }
    printf("%lld\n" , res);
}