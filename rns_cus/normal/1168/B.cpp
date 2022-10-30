#include <bits/stdc++.h>
using namespace std;

#define N 300300


char s[N];
bool check(int l, int r) {
    for (int x = l; x <= r; x ++) {
        for (int k = 1; 2 * k + x <= r; k ++) {
            if (s[x] == s[x+k] && s[x] == s[x+2*k]) return 1;
        }
    }
    return 0;
}

int main() {
    scanf("%s", &s);
    int n = strlen(s);
    long long rlt = 0;
    if (n > 20) rlt = 1ll * (n - 20) * (n - 19) / 2;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < 20; j ++) if (i + j < n && check(i, i + j)) rlt ++;
    }
    printf("%I64d\n", rlt);
}