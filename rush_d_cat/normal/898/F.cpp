#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;

const LL MOD = 1000000007;
const int N = 1000000+10;

char s[N]; int n;
LL pre[N], suf[N], t[N];

void init() {
    t[0] = 1;
    for (int i = 1; i <= n; i ++) {
        t[i] = t[i-1] * 10 % MOD;        
        pre[i] = (pre[i-1] * 10 + (s[i]-'0')) % MOD;
        suf[n-i+1] = (suf[n-i+2] + (s[n-i+1]-'0') * t[i-1] % MOD) % MOD;
    }
}

LL cac(int L, int R) {
    return ((pre[R] - pre[L-1] * t[R-L+1]) % MOD + MOD) % MOD;
}

int main() {
    scanf("%s", s + 1); n = strlen(s+1);
    init();

    for (int pos = 3; pos <= n; pos ++) {  // [pos, n]
        int len = n - pos + 1;

        int p1 = len;
        int p2 = pos - len;
        
        for (int d = -3; d <= 3; d ++) {
            if (p1 - d >= 1 && p1 - d + 1 <= pos - 1) {
                if ( (pre[p1-d] + cac(p1-d+1, pos-1)) % MOD == suf[pos]) {
                    if (s[p1-d+1]=='0' && pos-1 != p1-d+1) continue;
                    if (s[pos]=='0'&&pos!=n) continue;
                    for (int i = 1; i <= n; i ++) {
                        printf("%c", s[i]);
                        if (i == p1-d) printf("+");
                        if (i == pos-1) printf("=");
                    }
                    return 0;
                }
            }

            if (p2 - d >= 1 && p2 - d + 1 <= pos - 1) {
                if ( (pre[p2-d] + cac(p2-d+1, pos-1)) % MOD == suf[pos]) {
                    if (s[p2-d+1]=='0' && pos-1 != p2-d+1) continue;
                    if (s[pos]=='0'&&pos!=n) continue;
                    for (int i = 1; i <= n; i ++) {
                        printf("%c", s[i]);
                        if (i == p2-d) printf("+");
                        if (i == pos-1) printf("=");
                    }
                    return 0;
                }
            }

        }

    }



}