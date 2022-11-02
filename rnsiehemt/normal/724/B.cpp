#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxn = 25;

int n, m;
std::vector<int> v[maxn];

bool wee(std::vector<int> &w) {
    for (int i = 0; i < m; i++) if (w[i] != i) return false;
    return true;
}

bool good(std::vector<int> w, int x, int y) {
    std::vector<int> ww = w;

    std::swap(w[x], w[y]);
    for (int i = 0; i < m; i++) for (int j = 0; j < m; j++) {
        std::swap(w[i], w[j]);
        if (wee(w)) return true;
        std::swap(w[i], w[j]);
    }

    w = ww;

    for (int i = 0; i < m; i++) for (int j = 0; j < m; j++) {
        std::swap(w[i], w[j]);
        std::swap(w[x], w[y]);
        if (wee(w)) return true;
        std::swap(w[x], w[y]);
        std::swap(w[i], w[j]);
    }

    return false;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        v[i].resize(m);
        for (int j = 0; j < m; j++) {
            scanf("%d", &v[i][j]);
            v[i][j]--;
        }
    }
    for (int x = 0; x < m; x++) for (int y = x; y < m; y++) {
        bool yay = true;
        for (int i = 0; i < n; i++) {
            if (!good(v[i], x, y)) yay = false;
        }
        if (yay) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
}