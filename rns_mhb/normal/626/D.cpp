#include <bits/stdc++.h>
using namespace std;

#define M 10005

typedef long long ll;
int n;
int a[M];
int visp[M], vism[M];
ll b[M];
ll ans;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    for (int i = 0; i < n; i ++)
    for (int j = i + 1; j < n; j ++) {
        visp[a[j]-a[i]] ++;
    }
    for (int i = 0; i < M; i ++)
    for (int j = 0; j < M; j ++) {
        b[i+j] += 1ll * visp[i] * visp[j];
    }
    for (int i = 1; i < M; i ++) b[i] += b[i-1];
    for (int i = 0; i < M; i ++) ans += b[i] * visp[i+1];
    ll tot = n * (n - 1) / 2;
    tot = tot * tot * tot;
    printf("%.10lf\n", 1.0 * ans / tot);
}