#include <bits/stdc++.h>
using namespace std;
#define N 200200
typedef pair <int, int> pii;

int n, a;
long long ans;
pii dit[N];

int dist(int x) {
    int y = sqrt(x);
    return min(x - y * y, (y + 1) * (y + 1) - x);
}

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    int i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i ++) scanf("%d", &a), dit[i] = pii(dist(a), a);
    sort(dit, dit + n);
    i = lower_bound(dit, dit + n, pii(1, 0)) - dit;
    if (i < n / 2) for (j = i; j < n / 2; j ++) ans += dit[j].first;
    else for (j = n / 2; j < i; j ++) ans += 2 - (bool)dit[j].second;
    printf("%I64d\n", ans);

    return 0;
}