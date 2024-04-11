#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 52, MaxX = 100*1000+5;

struct flow {
    ll f[MaxN][MaxN];
    bool seen[MaxN];
    flow() {
        for (int i = 0; i < MaxN; i++) for (int j = 0; j < MaxN; j++) f[i][j] = 0;
    }
    ll push(int i, ll max, int end) {
        seen[i] = true;
        if (i == end) return max;
        for (int j = 0; j < MaxN; j++) if (!seen[j] && f[i][j]) {
            assert(f[i][j] > 0);
            ll k = push(j, std::min(max, f[i][j]), end);
            if (k) {
                f[i][j] -= k;
                f[j][i] += k;
                return k;
            }
        }
        return 0;
    }
    ll maxflow(int end) {
        ll ans = 0;
        while (ans < MaxX) {
            std::fill(seen, seen+MaxN, false);
            ll k = push(0, 1e9, end);
            if (!k) break;
            ans += k;
        }
        return ans;
    }
};

int N, M, X;
std::vector<std::pair<int,double>> e[MaxN];

bool go(double k) {
    flow f;
    for (int i = 0; i < N; i++) for (auto &j : e[i]) {
        int b = j.first; double c = j.second;
        f.f[i][b] = c/k;
    }
    return f.maxflow(N-1) >= X;
}

int main() {
    scanf("%d%d%d", &N, &M, &X);
    for (int i = 0; i < M; i++) {
        int a, b; double c; scanf("%d%d%lf", &a, &b, &c); a--; b--;
        e[a].eb(b, c);
    }
    double l = 0, h = 1e6;
    for (int i = 0; i < 80; i++) {
        double m = (l+h)/2;
        if (go(m)) l = m;
        else h = m;
    }
    printf("%.8lf\n", l*X);
}