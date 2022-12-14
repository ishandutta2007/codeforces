#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int cnt = 0;
ll a[100000];

void prepare() {
    for(int i = 1; i <= 63; i ++) {
        ll x = (1ll << i) - 1;
        for(int j = 0; j < i - 1; j ++) a[cnt ++] = x - (1ll << j);
    }
}

int main() {
	prepare();
	ll x, y;
    scanf("%I64d %I64d\n", &x, &y);
    int ans = 0;
    for(int i = 0; i < cnt; i ++) if(a[i] >= x && a[i] <= y) ans ++;
    printf("%d\n", ans);
}