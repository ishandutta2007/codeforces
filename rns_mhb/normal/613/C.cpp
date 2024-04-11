#include<bits/stdc++.h>
using namespace std;

int n, a[30], b[30];
char s[100010];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", a + i);
    int g = 0;
    for(int i = 1; i <= n; i ++) g = __gcd(g, a[i]);
    for(int d = g; d; d --) {
        if(g % d) continue;
        for(int i = 1; i <= n; i ++) b[i] = a[i] / d;
        int cnt = 0, odd;
        for(int i = 1; i <= n; i ++) if(b[i] & 1) cnt ++, odd = i;
        if(cnt > 1) continue;
        int len = 0;
        for(int i = 1; i <= n; i ++) len += b[i];
        if(len & 1) s[len>>1] = 'a' + odd - 1;
        int m = 0;
        for(int j = 1; j <= n; j ++) for(int k = b[j]/2; k; k --) {
            s[m ++] = 'a' + j - 1;
            s[len-m] = 'a' + j - 1;
        }
        s[len] = '\0';
        printf("%d\n", d * (2 - (len&1)));
        for(int i = 1; i <= d; i ++) printf("%s", s);
        puts("");
        return 0;
    }
    puts("0");
    for(int i = 1; i <= n; i ++) while(a[i] --) putchar('a' + i - 1);
    puts("");
}