#include<bits/stdc++.h>
using namespace std;

#define N 200010

int n, a[N];
map <pair<int, int>, int> mp;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    int ans = 0, cur = 0;
    for(int i = 1, x; i <= n; i ++) {
        scanf("%d", &x);
        if(a[i] == 0 && x == 0) ans ++;
        if(a[i]) {
            int g = __gcd(a[i], x);
            a[i] /= g, x /= g;
            if(a[i] < 0) a[i] *= -1, x *= -1;
            cur = max(cur, ++ mp[make_pair(a[i], x)]);
        }
    }
    printf("%d\n", ans + cur);
}