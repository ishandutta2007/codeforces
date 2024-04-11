#include <bits/stdc++.h>
using namespace std;

#define N 45

typedef long long ll;
int n, p;
ll ans;
char s[N];
int c[N];

int main() {
    scanf("%d %d ", &n, &p);
    for (int i = 0; i < n; i ++) {
        gets(s);
        if (!strcmp(s, "half")) c[i] = 0;
        else c[i] = 1;
    }
    ll now = 0;
    for (int i = n - 1; i >= 0; i --) {
        now = now << 1 | c[i];
        ans += now;
    }
    printf("%I64d\n", p / 2 * ans);
    return 0;
}