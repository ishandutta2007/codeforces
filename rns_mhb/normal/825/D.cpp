#include <bits/stdc++.h>
using namespace std;

#define N 1000005
#define K 26

typedef long long ll;
char s[N], t[N];
int a[K+5], b[K+5], cnt;

bool test(int x) {
    ll need = 0;
    for (int i = 0; i < K; i ++) {
        need += max(0ll, 1ll * b[i] * x - a[i]);
    }
    return need <= cnt;
}

int main() {
    gets(s);
    for (int i = 0; s[i]; i ++) {
        if (s[i] == '?') cnt ++;
        else a[s[i]-'a'] ++;
    }
    gets(t);
    for (int i = 0; t[i]; i ++) {
        b[t[i]-'a'] ++;
    }
    int st = 0, en = N;
    while (st < en) {
        int mid = st + en + 1 >> 1;
        if (test(mid)) st = mid;
        else en = mid - 1;
    }
    a[K] = -N;
    for (int i = 0, j = 0; s[i]; i ++) {
        if (s[i] != '?') putchar(s[i]);
        else {
            while (a[j] >= b[j] * st) j ++;
            a[j] ++;
            if (j < K) putchar('a' + j);
            else putchar('a');
        }
    }
    return 0;
}