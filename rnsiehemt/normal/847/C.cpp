#include <bits/stdc++.h>

const int maxn = 300*1000+5;

int n;
long long k;
char s[2*maxn];

int main() {
    scanf("%d%lld", &n, &k);
    n = n*2;
    int i = 0, cur = 0;
    while (i < n) {
        //printf("i = %d, cur = %d, k = %lld\n", i, cur, k);
        if (cur <= k) {
            s[i] = '(';
            k -= cur;
            cur++;
        } else {
            s[i] = ')';
            cur--;
        }
        i++;
    }
    if (cur != 0 || k != 0) {
        printf("Impossible\n");
    } else {
        printf("%s\n", s);
    }
}