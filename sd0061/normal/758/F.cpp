#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n , l , r;
int main() {
    cin >> n >> l >> r;
    if (n == 1) {
        printf("%d\n" , r - l + 1);
        return 0;
    }
    if (n == 2) {
        int p = r - l + 1;
        printf("%lld\n" , (LL)p * (p - 1));
        return 0;
    }
    -- n;
    if (n >= 24) {
        puts("0");
        return 0;
    }
    int res = 0;
    for (int a = 1 ;  ; ++ a) {
        int aa = 1;
        for (int i = 0 ; i < n ; ++ i) {
            aa = min(1LL << 30 , (long long)aa * a);
        }
        if (aa > r) break;
        int L = (l + aa - 1) / aa;
        for (int x = L * aa , p = L ; x <= r ; x += aa , ++ p) {
            // p * b^n <= r
            for (int b = a + 1 ;  ; ++ b) {
                if (__gcd(a , b) > 1) continue;
                int bb = p;
                for (int i = 0 ; i < n ; ++ i) {
                    bb = min(1LL << 30 , (long long)bb * b);
                }
                if (bb > r) break;
                res += 2;
            }
        }
    }
    cout << res << endl;
}