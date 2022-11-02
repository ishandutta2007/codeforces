#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxn = 1005;

int n, k, a, b, c, d;
bool seen[maxn];
std::vector<int> v;

void rip() {
    printf("-1\n");
    exit(0);
}

int main() {
    scanf("%d%d%d%d%d%d", &n, &k, &a, &b, &c, &d);
    if (n == 4) rip();
    else if (k < n+1) rip();
    else {
        seen[a] = seen[b] = seen[c] = seen[d] = true;
        v.pb(a); v.pb(d);
        for (int i = 1; i <= n; i++) if (!seen[i]) v.pb(i);
        v.pb(c);
        v.pb(b);
        for (int i = 0; i < n; i++) printf("%d%c", v[i], " \n"[i == n-1]);
        printf("%d %d ", c, b);
        for (int i = 2; i < sz(v)-2; i++) printf("%d ", v[i]);
        printf("%d %d\n", a, d);
    }
}