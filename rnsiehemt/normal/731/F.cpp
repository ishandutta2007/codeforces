#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxn = 200*1000+5;

int n;
ll c[maxn], d[maxn], ans;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        c[a]++;
    }
    for (int i = 0; i+1 < maxn; i++) d[i+1] = d[i] + c[i];
    for (int i = 1; i < maxn; i++) if (c[i]) {
        ll s = 0;
        for (int j = 0;; j += i) {
            int k = j+i;
            if (k >= maxn) k = maxn-1;
            s += j * (d[k] - d[j]);
            if (j+i >= maxn) break;
        }
        domax(ans, s);
    }
    printf("%lld\n", ans);
}