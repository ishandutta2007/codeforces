#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100005;
const int Q = 1e9 + 7;

int n , K , a[N];
char str[N];
int res;

LL p[N] , I[N] , power[N] , sum[N];
void dfs(int m , int k , int s , int x) {
    if (m == n) {
        if (k == K)
            res += s + x;
        return;
    }
    dfs(m + 1 , k , s , x * 10 + a[m]);
    if (k < K)
        dfs(m + 1 , k + 1 , s + x , a[m]);
}

LL C(int x , int y) {
    if (y < 0 || y > x) return 0;
    return p[x] * I[y] % Q * I[x - y] % Q;
}

void work() {
    int i;
    scanf("%d%d",&n,&K);
    scanf("%s" , str);
    for (i = 0 ; i < n ; ++ i)
        a[i] = str[i] - '0';
    //dfs(1 , 0 , 0 , a[0]);
    //cout << res << endl;
    power[0] = 1 , power[1] = 10;
    p[0] = p[1] = I[0] = I[1] = 1;
    for (i = 2 ; i <= n ; ++ i) {
        power[i] = power[i - 1] * 10 % Q;
        I[i] = (Q - Q / i) * I[Q % i] % Q;
    }
    for (i = 2 ; i <= n ; ++ i) {
        p[i] = p[i - 1] * i , p[i] %= Q;
        I[i] *= I[i - 1] , I[i] %= Q;
    }
    sum[0] = power[0] * C(n - 2 , K - 1) % Q;
    for (i = 1 ; i <= n ; ++ i) {
        sum[i] = sum[i - 1];
        sum[i] += power[i] * C(n - i - 2 , K - 1) % Q;
        sum[i] %= Q;
    }
    LL ans = 0;
    for (i = 0 ; i < n ; ++ i) {
        if (n - i - 2 >= 0)
            ans += a[i] * sum[n - i - 2] % Q;
        ans %= Q;
        ans += a[i] * power[n - i - 1] % Q * C(i , K) % Q;
        ans %= Q;
    }
    cout << ans << endl;
}

int main() {
    work();
    return 0;
}