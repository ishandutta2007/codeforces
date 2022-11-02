#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxn = 22;

int n, k;
double p[maxn], q[(1<<20) + 5], ans[maxn];

int bc(int x) {
    int c = 0;
    for (int i = 0; i < n; i++) if (x & (1<<i)) c++;
    return c;
}

int main() {
    scanf("%d%d", &n, &k);
    int nonz = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lf", p+i);
        if (p[i]) nonz++;
    }
    domin(k, nonz);
    q[0] = 1;
    for (int i = 0; i < (1<<n); i++) {
        double cp = 0;
        for (int j = 0; j < n; j++) if (!(i & (1<<j))) {
            cp += p[j];
        }
        if (cp) {
            //printf("riprip\n");
            for (int j = 0; j < n; j++) if (!(i & (1<<j))) {
                q[i | (1<<j)] += q[i] * p[j] / cp;
            }
        }
        if (bc(i) == k) {
            for (int j = 0; j < n; j++) if (i & (1<<j)) {
                ans[j] += q[i];
            }
        }
    }
    for (int i = 0; i < n; i++) printf("%.8lf%c", ans[i], " \n"[i == n-1]);
}