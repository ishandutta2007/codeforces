#include <bits/stdc++.h>

using namespace std;

#define N 100100

char s[N];
char A[N];
int f[N], g[N], ff[N], gg[N];

int n;

void print(int a, int b, int p) {
    for(int i = a; i < n / 2; i ++) A[p ++] = '4';
    for(int i = b; i < n / 2; i ++) A[p ++] = '7';
    A[p] = 0; puts(A);
}

bool can(int a, int b, int p) {
    if(a > n / 2 || b > n / 2 ) return 0;
    b = n / 2 - b;
    a = n / 2 - a;
    if(b) {
        if(f[p] - p < b) {
            if(g[p] == f[p]) return 0;
            return 1;
        }
    }
    if(a) {
        p += b;
        if(ff[p] - p < a && ff[p] == gg[p]) return 0;
    }
    return 1;
}

int main() {
    scanf("%s", s);
    n = strlen(s);
    int a = 0, b = 0;
    if(n & 1) {
        for(int i = 0; i <= n / 2; i ++) putchar('4');
        for(int i = 0; i <= n / 2; i ++) putchar('7'); puts("");
        return 0;
    }
    int cf = n, cg = n;
    for(int i = n - 1; i >= 0; i --) {
        if(s[i] != '7') cf = i;
        if(s[i] > '7') cg = i;
        f[i] = cf; g[i] = cg;
    }
    cf = n, cg = n;
    for(int i = n - 1; i >= 0; i --) {
        if(s[i] != '4') cf = i;
        if(s[i] > '4') cg = i;
        ff[i] = cf; gg[i] = cg;
    }
    int ok = 1;
    for(int i = 0; i < n; i ++) {
        if(s[i] < '4' && a + 1 - b <= n - i - 1) {
            A[i] = '4'; print(a + 1, b, i + 1); return 0;
        }
        if(s[i] == '4') {
            A[i] = '4';
            if(can(a + 1, b, i + 1)) {
                a ++;
                continue;
            }
        }
        if(s[i] < '7' && b + 1 - a <= n - i - 1) {
            A[i] = '7'; print(a, b + 1, i + 1); return 0;
        }
        if(s[i] == '7') {
            A[i] = '7'; if(can(a, b + 1, i + 1)) {
                b ++;
                continue;
            }
        }
        ok = 0;
        break;
    }
    if(ok) {
        A[n] = 0; puts(A); return 0;
    }
    for(int i = 0; i <= n / 2; i ++) putchar('4');
    for(int i = 0; i <= n / 2; i ++) putchar('7'); puts("");
    return 0;
}