#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

#define mod(x) ((x)%Mod)

const int maxn = 100*1000+5, maxb = 61;
const ll Mod = 1000*1000*1000+7;

int n, m;
std::vector<std::pair<int, ll>> e[maxn];
bool seen[maxn], done[maxn];
ll xorto[maxn], c[2][maxb+5], d[2][maxb+5], ans;

std::vector<ll> cycles;
void go(int i, int p) {
    seen[i] = true;
    for (auto &k : e[i]) {
        int j; ll t; std::tie(j, t) = k;
        if (j == p) continue;
        if (seen[j]) {
            cycles.pb(xorto[i] ^ xorto[j] ^ t);
        } else {
            xorto[j] = xorto[i] ^ t;
            go(j, i);
        }
    }
}

void dobits(ll &t) {
    for (int i = 0; i < maxb; i++) if (t & (1ll << i)) std::swap(c[0][i], c[1][i]);
}

void add(ll &a, ll b) {
    a += b;
    if (a >= Mod) a -= Mod;
}

void ho(int i, int p) {
    done[i] = true;
    for (int i = 0; i < maxb; i++) {
        add(d[0][i], mod(c[0][i]));
        add(d[1][i], mod(c[1][i]));
    }
    for (int i = 0; i < maxb; i++) c[0][i]++;
    for (auto &k : e[i]) {
        int j; ll t; std::tie(j, t) = k;
        if (j == p) continue;
        if (!done[j]) {
            dobits(t);
            ho(j, i);
            dobits(t);
        }
    }
}

void simplify(std::vector<ll> &v) {
    std::priority_queue<ll> q;
    for (ll &l : v) if (l) q.push(l);
    v.clear();
    while (sz(q) >= 2) {
        ll l = q.top(); q.pop();
        ll m = q.top();
        if ((l&m)*2 > l) {
            if (l^m) q.push(l^m);
        } else {
            v.pb(l);
        }
    }
    while (!q.empty()) {
        v.pb(q.top()); q.pop();
    }
}

void solve(int r) {
    cycles.clear();
    go(r, -1);
    simplify(cycles);
    for (int i = 0; i < maxb; i++) c[0][i] = c[1][i] = 0;
    for (int i = 0; i < maxb; i++) d[0][i] = d[1][i] = 0;
    ho(r, -1);
    for (int i = 0; i < maxb; i++) {
        ll d0 = d[0][i], d1 = d[1][i];
        for (ll &l : cycles) {
            if (l & (1ll << i)) {
                add(d1, d0);
                d0 = d1;
            } else {
                add(d1, d1);
                add(d0, d0);
            }
        }
        add(ans, mod(d1 * mod(1ll << i)));
    }
}

int main() {
    //cycles.push_back(11);
    //cycles.push_back(5);
    //cycles.push_back(12);
    //simplify(cycles);
    //for (ll &x : cycles) printf("%lld\n", x);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v; ll t; scanf("%d%d%lld", &u, &v, &t);
        u--; v--;
        e[u].eb(v, t);
        e[v].eb(u, t);
    }

    for (int i = 0; i < n; i++) if (!seen[i]) solve(i);
    
    printf("%lld\n", ans);
}