// abc
#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxn = 105;

int n, a[maxn], d[maxn], ans;
std::vector<std::pair<int, int>> v, w;

int place(int i) {
    int p = 1;
    for (int j = 0; j < n; j++) if (j != i && (a[j] > a[i] || (a[j] == a[i] && j < i))) p++;
    return p;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", a+i, d+i);
        if (d[i] > 0) v.eb(-a[i], i);
        else w.eb(-a[i], i);
    }
    std::sort(all(v)); std::reverse(all(v));
    std::sort(all(w));
    for (auto &p : w) v.pb(p);
    for (auto &p : v) {
        int i = p.second;
        //printf("doing %d\n", i);
        int x = place(i);
        a[i] += d[i];
        int y = place(i);
        ans += std::abs(x-y);
    }
    printf("%d\n", ans);
}