#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxn = 200*1000+5;

int n, min, max, ans;
ll k, a[maxn], b[maxn], c[maxn];

int main() {
    scanf("%d%lld", &n, &k); n++;
    for (int i = 0; i < n; i++) scanf("%lld", a+i);
    max = n;
    b[0] = a[0];
    for (int i = 1; i < n; i++) {
        if (std::abs(b[i-1]) & 1ll) {
            max = i;
            break;
        } else {
            b[i] = b[i-1] / 2 + a[i];
        }
    }
    min = 0;
    c[n-1] = a[n-1];
    for (int i = n-2; i >= 0; i--) {
        c[i] = c[i+1] * 2 + a[i];
        if (std::abs(c[i]) > 2*k + 5) {
            min = i+1;
            break;
        }
    }
    for (int i = min; i < max; i++) {
        ll v = -(b[i] + c[i] - a[i] - a[i]);
        if (std::abs(v) <= k) {
            if (i == n-1 && v == 0) ans--;
            ans++;
        }
    }
    printf("%d\n", ans);
}