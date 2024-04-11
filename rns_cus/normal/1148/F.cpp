#include <bits/stdc++.h>
using namespace std;

#define N 300300

typedef long long ll;

int n, val[N];
ll mask[N];

vector <int> vec[100];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d %I64d", &val[i], &mask[i]);
    ll sum = 0;
    for (int i = 1; i <= n; i ++) sum += val[i];
    if (sum < 0) {
        for (int i = 1; i <= n; i ++) val[i] = -val[i];
    }
    for (int i = 1; i <= n; i ++) vec[__lg(mask[i])].push_back(i);
    ll s = 0;
    for (int k = 0; k < 62; k ++) {
        int sz = vec[k].size();
        ll x = 0, y = 0;
        for (int i = 0; i < sz; i ++) {
            if (__builtin_popcountll(mask[vec[k][i]] & s) & 1) x += val[vec[k][i]];
            else y += val[vec[k][i]];
        }
        if (x <= y) s ^= 1ll << k;
    }
    printf("%I64d\n", s);

    return 0;
}