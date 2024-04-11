#include<bits/stdc++.h>
using namespace std;

#define N 500010

int n, k;
long long a[N], s[N], t[N], u[N];

int main() {
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i ++) scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    for(int i = 1; i <= n; i ++) s[i] = s[i - 1] + a[i];
    long long ans = 0;
    if(!k) {
        for(int i = 1; i <= n - 1; i ++) ans += s[i];
        printf("%lld\n", ans);
        return 0;
    }
    t[n + 1] = 0;
    for(int i = n; i >= 1; i --) {
        t[i] = t[i + 1] + a[i] * ((n - i) / (k + 1));
    }
    long long sum = 0;
    u[0] = t[1];
    for(int i = 1; i <= n; i ++) {
        sum += s[i - 1];
        u[i] = sum + s[i] * ((s[i] < 0 ? n - i : n - i + k) / (k + 1)) + t[i + 1];
    }
    ans = *max_element(u + 1, u + n + 1);
    printf("%lld\n", ans);
}