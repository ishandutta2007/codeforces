#include <bits/stdc++.h>
using namespace std;
#define M 200200
typedef long long ll;
typedef pair<ll, ll> pll;

int n;
ll T;
pll pp[M];
bool cmp(pll a, pll b) {
    return a.first * b.second != a.second * b.first ? a.first * b.second > a.second * b.first : a.first > b.first;
}
ll p[M], t[M];
bool ok(int i, int j) {
    return p[i] * t[j] == p[j] * t[i];
}

int id[M];
bool cmp1(int i, int j) {
    return p[i] != p[j] ? p[i] < p[j] : i < j;
}

int pre[M], nxt[M];
double tt[M];
bool ok(double c) {
    double mx = 0;
    for (int j, i = 1; i <= n; i = j) {
        for (j = i; j <= n && p[id[j]] == p[id[i]]; j++) {
            int k = id[j];
            double pp = p[k] * (1 - c * tt[nxt[k]] / T);
            if (pp < mx) {
                return 0;
            }
        }

        for (j = i; j <= n && p[id[j]] == p[id[i]]; j++) {
            int k = id[j];
            double pp = p[k] * (1 - c * (tt[pre[k]-1] + t[k]) / T);
            mx = max(mx, pp);
        }
    }
    return 1;
}

int main() {
    //freopen("D2.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%I64d", &pp[i].first);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%I64d", &pp[i].second);
    }
    sort(pp + 1, pp + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        p[i] = pp[i].first;
        t[i] = pp[i].second;
        //printf("%I64d %I64d\n", p[i], t[i]);
        tt[i] = tt[i-1] + t[i];
        id[i] = i;
        T += t[i];
    }

    pre[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (ok(i, i - 1)) {
            pre[i] = pre[i-1];
        } else {
            pre[i] = i;
        }
    }

    nxt[n] = n;
    for (int i = n - 1; i >= 1; i--) {
        if (ok(i, i + 1)) {
            nxt[i] = nxt[i+1];
        } else {
            nxt[i] = i;
        }
    }

    sort(id + 1, id + n + 1, cmp1);
    double mn = 0, mx = 1;
    for (int step = 0; step < 100; step++) {
        double mid = (mn + mx) / 2;
        if (ok(mid)) {
            mn = mid;
        } else {
            mx = mid;
        }
    }
    printf("%.11lf\n", mn);
    return 0;
}