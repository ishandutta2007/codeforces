#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
#define N 201000
pi A[N];
ll f[N], g[N];
double F[N];
pi calc(int x, int y) {
    ll a = (A[x].first - g[y] - 1) / A[y].second + 1;
    ll b = 1ll * A[y].second * a - (A[x].first - g[y]);
    return pi(a + f[y], -b);
}

double Ca(int x, int y) {
    return (F[y] - F[x]) / (1.0 / A[x].second - 1.0 / A[y].second);
}

int B[N];

int main() {
    //freopen("2.in", "r", stdin);
    int n;
    ll S;
    scanf("%d%I64d", &n, &S);
    ll ans = S;
    for(int i = 1; i <= n; i ++) scanf("%I64d%I64d", &A[i].second, &A[i].first);
    sort(A + 1, A + n + 1);
    ll mx = 0;
    int st = 0;
    int en = 0;
    int xx = 0;
    for(int i = 1; i <= n; i ++) {
        if(A[i].second <= mx) continue;
        mx = max(mx, A[i].second);
        if(i == 1) {
            f[1] = 0;
            g[1] = 0;
        } else {
            while(en - 1 > st) {
                if(Ca(B[st], B[st + 1]) < A[i].first) st ++;
                else break;
            }
            pi a = calc(i, B[st]);
            f[i] = a.first;
            g[i] = -a.second;
            int x = B[st];
            for(int j = st + 1; j < en; j ++) {
                a = calc(i, B[j]);
                if(a.first > f[i]) break;
                if(g[i] < -a.second) g[i] = -a.second, x = B[j];
            }
        }
        ll p = f[i] + (S - g[i] - 1) / A[i].second + 1;
        if(ans > p) ans = p, xx = i;
        F[i] = 1.0 * f[i] - 1.0 * g[i] / A[i].second;
        while(en - 1 > st) {
            if(Ca(B[en - 2], B[en - 1]) > Ca(B[en - 1], i)) en --;
            else break;
        }
        B[en ++] = i;
    }
    printf("%I64d\n", ans);
    return 0;
}