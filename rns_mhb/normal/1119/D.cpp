#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define N 100010

ll s[N], b[N], c[N];
int n, q;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%I64d", &s[i]);
    sort(s + 1, s + n + 1);
    for(int i = 1; i < n; i ++) b[i] = s[i+1] - s[i];
    sort(b + 1, b + n);
    for(int i = 1; i < n; i ++) c[i] = c[i-1] + b[i];
    scanf("%d", &q);
    while(q --) {
        ll l, r;
        scanf("%I64d%I64d", &l, &r);
        r = r - l + 1;
        int x = lower_bound(b + 1, b + n, r) - b;
        printf("%I64d ", c[x-1] + (n - x + 1) * r);
    }
    puts("");
}