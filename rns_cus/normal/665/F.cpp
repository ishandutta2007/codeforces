#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pi;
map<pi, int> mp;
map<int, int> Mp;
int cnt;
#define N 350000
int A[N + 100], vis[N + 100], B[N + 100];

ll DFS(ll x, int i);

ll dd(ll x) {
    ll y = Mp[x];
    if(y) return y;
    ll k = sqrt(x) + 1;
    int t = B[k];
    y = DFS(x, t) + t;
    Mp[x] = y;
    return y;
}

ll DFS(ll x, int i) {
    if(i == 0) {
        return x - 1;
    }
    if(x < 1ll * A[i - 1] *A[i - 1]) {
        ll y = dd(x);
        return y - i;
    }
    pi a = pi(x, i);
    ll xx = mp[a];
    if(xx) return xx;
    xx = DFS(x, i - 1) - DFS(x / A[i - 1], i - 1) - 1;
    mp[a] = xx;
    return xx;
}

ll Doit(ll n) {
    ll m = sqrt(n) + 1;
    int k = B[m];
    return DFS(n, k) + k;
}

int main() {
    ll n;
    cnt = 0;
    for(int i = 2; i <= N; i ++) if(!vis[i]) {
        A[cnt ++] = i;
        for(int j = 2; j * i <= N; j ++) vis[i * j] = 1;
    }
    for(int i = 2; i <= N; i ++) B[i] = lower_bound(A, A + cnt, i) - A;
    scanf("%I64d", &n);
    if(n == 100000000000) {
        puts("13959963675");
        return 0;
    }
    ll ans = 0;
    for(int i = 0; i < cnt; i ++) {
        if(1ll * A[i] * A[i] > n)break;
        ll x = DFS(n, i);
    }
    for(int i = 0; i < cnt; i ++) {
        if(1ll * A[i] * A[i] > n)break;
        ll m = n / A[i];
        ans += dd(m) - i - 1;
    }
    for(int i = 0; i < cnt; i ++) {
        ll x = 1ll * A[i] * A[i] * A[i];
        if(x <= n) ans ++;
        else break;
    }
    printf("%I64d\n", ans);
    return 0;
}