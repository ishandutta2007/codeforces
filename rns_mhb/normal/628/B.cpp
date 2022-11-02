#include <bits/stdc++.h>
using namespace std;

#define N 300005

typedef long long ll;
int n;
char s[N];
ll ans;

int main() {
    gets(s);
    n = strlen(s);
    if ((s[0] - '0') % 4 == 0) ans ++;
    for (int i = 1; i < n; i ++) {
        if ((s[i] - '0') % 4 == 0) ans ++;
        if ((2 * (s[i-1] - '0') + s[i] - '0') % 4 == 0) ans += i;
    }
    printf("%I64d\n", ans);
    return 0;
}