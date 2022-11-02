#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxn = 1000*1000+5, maxx = 3*1000*1000+5;

int n, m;
ll c[maxx];
ll d[maxx], ans[maxx];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        c[a]++;
    }
    ll s = 0;
    for (int j = 1; j < maxx; j++) {
        ll missed = n-1;
        for (int k = 1; j*k < maxx; k++) {
            if (k != j) {
                d[j*k] += c[j] * c[k];
                missed -= c[k];
            } else {
                d[j*j] += c[j] * (c[j] - 1);
                missed -= c[j] - 1;
            }
        }
        missed *= c[j];
        s += missed;
    }
    for (int i = maxx-1; i >= 1; i--) {
        s += d[i];
        ans[i] = s;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int p; scanf("%d", &p);
        printf("%lld\n", ans[p]);
    }
}