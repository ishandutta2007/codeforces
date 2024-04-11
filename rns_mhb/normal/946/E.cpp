#include <bits/stdc++.h>
using namespace std;
#define pc putchar
#define f0(i, a, b) for (int i = a; i < b; i ++)
#define f1(i, a, b) for (int i = a; i <= b; i ++)
#define f3(i, a, b) for (int i = a; i >= b; i --)
#define N 200005

int a[N][10], b[N], c[10];
char s[N];

int main() {
    int T;
    for (scanf("%d", &T); T --; ) {
        scanf("%s", s+1);
        int ls = strlen(s+1), p;
        f1(i, 1, ls) s[i] -= '0';
        f1(i, 1, ls) {
			f0(j, 0, 10) a[i][j] = a[i-1][j];
            a[i][s[i]] ^= 1;
			if (s[i]) p = i;
            b[i] = p;
        }
        memset(c, 0, sizeof c);
        bool flag = 0;
        int g, gs = 0, left = ls - 2, ch; p = 0;
        f1(i, 1, ls) {
            f0(j, 0, s[i]) {
                if (i == 1 && j == 0) continue;
                a[i][j] ^= 1;
                a[i][s[i]] ^= 1;
                g = 0;
                f0(k, 0, 10) if (a[i][k]) g ++;
                if (g <= ls - i) {
                    p = b[i];
                    ch = j;
                    gs = i - b[i];
                    f0(k, 0, 10) c[k] = a[i][k];
                    left = ls - i - g;
                }
                a[i][j] ^= 1;
                a[i][s[i]] ^= 1;
            }
        }
        f0(i, 1, p) pc('0'+s[i]);
        if (p) pc('0'+ch);
        f0(i, 0, gs) pc('9');
        f0(i, 0, left) pc('9');
        f3(j, 9, 0) if (c[j]) pc(j+'0');
        puts("");
    }
}