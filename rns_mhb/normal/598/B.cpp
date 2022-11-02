#include <bits/stdc++.h>
using namespace std;

#define N 10005

char s[N], t[N];
int q, l, r, k;

int main() {
    gets(s + 1);
    scanf("%d", &q);
    while (q --) {
        scanf("%d %d %d", &l, &r, &k);
        for (int i = l; i <= r; i ++) {
            t[(i-l+k) % (r-l+1) + l] = s[i];
        }
        for (int i = l; i <= r; i ++) s[i] = t[i];
    }
    puts(s + 1);
}