#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 150*1000+5;

int N, t[MaxN], ans;
std::vector<int> v, w;
bool inw[MaxN];

bool good(int i) {
    if (i < 0 || i >= N-1) return true;
    else if (i&1) return t[i+1] < t[i];
    else return t[i+1] > t[i];
}
void go(int i, int j) {
    int add = 1;
    std::swap(t[i], t[j]);
    for (int k : v) if (!good(k)) add = 0;
    if (!good(i-1)) add = 0;
    if (!good(i)) add = 0;
    if (!good(j-1)) add = 0;
    if (!good(j)) add = 0;
    ans += add;
    std::swap(t[i], t[j]);
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", t+i);
    for (int i = 0; i+1 < N; i++) if (!good(i)) {
        v.pb(i);
        w.pb(i);
        w.pb(i+1);
    }
    if (sz(v) > 5) {
        printf("0\n");
        return 0;
    }
    std::sort(all(w));
    w.erase(std::unique(all(w)), w.end());
    for (int i : w) inw[i] = true;
    for (int i : w) for (int j = 0; j < N; j++) if (!inw[j] || i < j) {
        go(i, j);
    }
    printf("%d\n", ans);
}