#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxn = 5005;

int n, m, w, q;
std::vector<int> e[maxn];
std::vector<std::pair<ll, ll>> v[maxn];
std::priority_queue<std::pair<ll, ll>> pq;
ll tk, tp;
bool seen[maxn];
int start; ll K, P;

void add(std::pair<ll, ll> v) {
    ll k, p; std::tie(k, p) = v;
    pq.emplace(p, k);
    tk += k;
    tp += k*p;
    while (tk > K) {
        std::tie(p, k) = pq.top(); pq.pop();
        tk -= k;
        tp -= k*p;
        if (tk < K) {
            ll add = K - tk;
            pq.emplace(p, add);
            tk += add;
            tp += add * p;
            break;
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int x, y; scanf("%d%d", &x, &y); x--; y--;
        e[x].pb(y); e[y].pb(x);
    }
    scanf("%d", &w);
    for (int i = 0; i < w; i++) {
        int c; ll k, p; scanf("%d%lld%lld", &c, &k, &p); c--;
        v[c].eb(k, p);
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        while (!pq.empty()) pq.pop();
        tk = tp = 0;
        std::fill(seen, seen+n, false);
        scanf("%d%lld%lld", &start, &K, &P); start--;
        std::queue<std::pair<int, int>> q;
        seen[start] = true;
        q.emplace(start, 0);
        int ans = -1;
        while (!q.empty()) {
            int x, d; std::tie(x, d) = q.front(); q.pop(); // xd
            for (auto &p : v[x]) add(p);
            if (tk >= K && tp <= P) {
                assert(tk == K);
                ans = d;
                break;
            }
            for (auto &y : e[x]) if (!seen[y]) {
                seen[y] = true;
                q.emplace(y, d+1);
            }
        }
        printf("%d\n", ans);
    }
}