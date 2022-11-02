#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxn = 300*1000+5;

int n, a[maxn], ans[maxn], best[2][maxn], allbest[2];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a+i);
        a[i] = -a[i];
    }

    ans[n-1] = *std::min_element(a, a+n);

    {
        int parity = n%2;
        for (int i = 0; i+1 < n; i++) {
            int inside = 2 * (std::min(i, n-1 - (i+1)) + 1);
            int needed = n - inside;
            assert(needed >= 0);
            domin(best[parity][needed], std::min(a[i], a[i+1]));
        }
    }
    {
        int parity = 1 - (n%2);
        for (int i = 1; i+1 < n; i++) {
            int inside = std::min(n-1 - i, i) * 2 + 1;
            int needed = n - inside;
            assert(needed >= 0);
            domin(best[parity][needed], std::min(std::max(a[i-1], a[i]), std::max(a[i], a[i+1])));
        }
    }
    for (int i = 0; i < n-1; i++) {
        domin(allbest[0], best[0][i]);
        domin(allbest[1], best[1][i]);
        ans[i] = allbest[i % 2];
    }
    for (int i = 0; i < n; i++) printf("%d%c", -ans[i], " \n"[i == n-1]);
}