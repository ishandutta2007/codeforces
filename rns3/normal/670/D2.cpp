#include <bits/stdc++.h>
using namespace std;

#define max(a,b) (a>b?a:b)

int n;
typedef long long ll;
const int M = 2000001;
const int inf = 1e9 + 1;
int a[M], b[M];

long long calc(ll x) {
    ll tot = 0;
    for(int i = 1; i <= n; i ++) {
        tot += max(0, 1ll * a[i] * x - b[i]);
        if(tot > inf) tot = inf;
    }
    return tot;
}

int main() {
    int k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i ++) scanf("%d", &b[i]);
    ll st = 0, en = 2 * inf + 1;
    while(en > st + 1) {
        ll mid = (en + st) / 2;
        if(calc(mid) > k) en = mid;
        else st = mid;
    }
    cout << st << endl;
}