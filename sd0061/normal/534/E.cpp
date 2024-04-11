#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 500005;
const int M = 1000005;
int n , m , p[N];
int cnt[N] , s[N];
int a[N << 2];
LL w[N << 2];
vector<LL> res;
void work() {
    int i , j , x;
    scanf("%d" , &n);
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d" , &x);
        p[i] = x;
    }
    scanf("%d" , &m);
    for (i = 1 ; i <= m ; ++ i) {
        scanf("%d" , &x);
        ++ cnt[x];
    }
    j = 0;
    while (j < M) {
        x = 1;
        while (j < M && x < n)
            a[++ j] = x ++;
        x = n;
        while (j < M && x > 1)
            a[++ j] = x --;
    }
    for (i = 2 ; i <= M ; ++ i)
        w[i] = w[i - 1] + abs(p[a[i]] - p[a[i - 1]]);
    for (i = 1 ; i <= m ; ++ i) {
        ++ s[a[i]];
    }
    int eq = 0;
    for (i = 1 ; i <= n ; ++ i)
        if (s[i] == cnt[i])
            ++ eq;
    for (i = 1 ; i + m - 1 <= M ; ++ i) {
        if (eq == n) {
            res.push_back(w[i + m - 1] - w[i]);
        }
        if (s[a[i]] == cnt[a[i]]) -- eq;
        -- s[a[i]];
        if (s[a[i]] == cnt[a[i]]) ++ eq;
        if (s[a[i + m]] == cnt[a[i + m]]) -- eq;
        ++ s[a[i + m]];
        if (s[a[i + m]] == cnt[a[i + m]]) ++ eq;
    }
    if (res.empty())
        puts("-1");
    else {
        sort(res.begin() , res.end());
        if (unique(res.begin() , res.end()) - res.begin() == 1) {
            printf("%lld\n" , res.back());
        } else {
            puts("-1");
        }
    }

}

int main() {
    work();
    return 0;
}