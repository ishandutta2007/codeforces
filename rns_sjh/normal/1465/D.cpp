#include<bits/stdc++.h>
using namespace std;

#define N 100010

int n, k, a[N], b[N], c[N], d[N];
char s[N];
int x, y;

int main() {
    scanf("%s", s);
    scanf("%d%d", &x, &y);
    n = strlen(s);
    vector<int> pos;
    for(int i = 0; i < n; i ++) if(s[i] == '?') k ++, pos.push_back(i);
    for(int i = 1; i < n; i ++) {
        a[i] = a[i - 1] + (s[i - 1] == '0');
        b[i] = b[i - 1] + (s[i - 1] == '1');
    }
    for(int i = n - 2; i >= 0; i --) {
        c[i] = c[i + 1] + (s[i + 1] == '0');
        d[i] = d[i + 1] + (s[i + 1] == '1');
    }
    long long ans = 1e18;
    long long rlt = 0;
    for(int i = 0; i < n; i ++) {
        if(s[i] == '0') rlt += 1ll * b[i] * y + 1ll * d[i] * x;
        else if(s[i] == '1') rlt += 1ll * a[i] * x + 1ll * c[i] * y;
        else rlt += 2ll * b[i] * y + 2ll * d[i] * x;
    }
    rlt >>= 1;
    ans = min(ans, rlt);
    for(int i = k - 1; i >= 0; i --) {
        int j = pos[i];
        rlt -= 1ll * b[j] * y + 1ll * d[j] * x;
        rlt += 1ll * a[j] * x + 1ll * c[j] * y;
        ans = min(ans, rlt + 1ll * i * (k - i) * x);
    }
    for(int i = k - 1; i >= 0; i --) {
        int j = pos[i];
        rlt -= 1ll * a[j] * x + 1ll * c[j] * y;
        rlt += 1ll * b[j] * y + 1ll * d[j] * x;
        ans = min(ans, rlt + 1ll * i * (k - i) * y);
    }
    printf("%lld\n", ans);
}