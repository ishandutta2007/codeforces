#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

typedef std::set<std::pair<ll, ll>> count_t;

const int maxn = 100*1000+5;

int n, sz[maxn], par[maxn];
ll M, tens[maxn], ans, inv[maxn];
std::set<std::pair<int, ll>> e[maxn];

void ho(int i, int p, std::vector<int> &v) {
    par[i] = p;
    v.pb(i);
    sz[i] = 1;
    for (auto &f : e[i]) if (f.first != p) {
        ho(f.first, i, v);
        sz[i] += sz[f.first];
    }
}

void add(std::set<std::pair<ll, ll>> &counts, ll a) {
    assert(a < M);
    auto it = counts.lower_bound({a, 0});
    if (it != counts.end() && it->first == a) {
        ll c = it->second;
        counts.erase(it);
        counts.insert({a, c+1});
    } else counts.insert({a, 1});
}

void rem(std::set<std::pair<ll, ll>> &counts, ll a) {
    assert(a < M);
    auto it = counts.lower_bound({a, 0});
    assert(it != counts.end() && it->first == a);
    ll c = it->second;
    assert(c > 0);
    counts.erase(it);
    counts.insert({a, c-1});
}

ll get(std::set<std::pair<ll, ll>> &counts, ll a) {
    assert(a < M);
    auto it = counts.lower_bound({a, 0});
    if (it != counts.end() && it->first == a) {
        ll c = it->second;
        return c;
    } else return 0ll;
}

void io(int i, int p, int d, ll x, count_t &counts, bool adding) {
    if (adding) add(counts, x);
    else rem(counts, x);
    for (auto &f : e[i]) if (f.first != p) {
        int j = f.first;
        io(j, i, d+1, (x + tens[d] * f.second) % M, counts, adding);
    }
}

void jo(int i, int p, int d, ll x, count_t &counts) {
    // add ans
    ll aoeu = M - x;
    if (aoeu == M) aoeu = 0;
    //printf("at %d, x = %lld, d = %d, searching for %lld\n", i, x, d, (aoeu * inv[d]) % M);
    ans += get(counts, (aoeu * inv[d]) % M);
    //printf("got %lld\n", get(counts, (aoeu * inv[d]) % M));
    for (auto &f : e[i]) if (f.first != p) {
        int j = f.first;
        jo(j, i, d+1, (x * 10 + f.second) % M, counts);
    }
}

void go(int i) {
    std::vector<int> v;
    ho(i, -1, v);

    int centre = -1;
    for (int i : v) {
        bool good = true;
        for (auto &f : e[i]) if (f.first != par[i]) if (sz[f.first] > sz(v)/2+1) {
            good = false;
            break;
        }
        if (sz[i] < sz(v)/2 - 1) good = false;
        if (good) {
            centre = i;
            break;
        }
    }
    assert(centre != -1);

    // do shit
    std::set<std::pair<ll, ll>> counts;
    for (auto &f : e[centre]) io(f.first, centre, 1, f.second % M, counts, true);
    //printf("centre = %d\n", centre);
    //for (auto &x : counts) printf("%lld %lld\n", x.first, x.second);
    ans += get(counts, 0);
    //printf("zerocount = %lld\n", get(counts, 0));
    add(counts, 0);
    for (auto &f : e[centre]) {
        io(f.first, centre, 1, f.second % M, counts, false);
        //printf("removing %d\n", f.first);
        //for (auto &x : counts) printf("%lld %lld\n", x.first, x.second);
        jo(f.first, centre, 1, f.second % M, counts);
        io(f.first, centre, 1, f.second % M, counts, true);
    }

    //printf("decomping %d\n", centre);
    for (auto &f : e[centre]) {
        int j = f.first;
        //printf("\t%d into %d\n", centre, j);
        e[j].erase({centre, f.second});
        go(j);
    }
}

ll modexp(ll b, ll e) {
    ll x = 1ll;
    while (e) {
        if (e&1) x = (x*b) % M;
        e >>= 1;
        b = (b*b) % M;
    }
    return x;
}

std::pair<ll, ll> ee(ll a, ll b) {
    if (a%b) {
        auto p = ee(b, a%b);
        return {p.second, p.first - p.second*(a/b)};
    } return {0ll, 1ll};
}

int main() {
    scanf("%d%lld", &n, &M);
    for (int i = 0; i < n-1; i++) {
        int a, b; ll d; scanf("%d%d%lld", &a, &b, &d);
        e[a].insert({b, d});
        e[b].insert({a, d});
    }

    if (M == 1) {
        printf("%lld\n", ll(n) * (n-1));;
        return 0;
    }

    tens[0] = 1;
    for (int i = 1; i < maxn; i++) tens[i] = (tens[i-1] * 10) % M;
    inv[0] = 1;
    //inv[1] = modexp(10, M-2);
    inv[1] = (ee(10, M).first + M) % M;
    //printf("mod inv of %d mod %lld is %lld\n", 10, M, inv[1]);
    for (int i = 2; i < maxn; i++) inv[i] = (inv[i-1] * inv[1]) % M;

    //for (int i = 0; i < 10; i++) printf("%lld\n", inv[i]);
    //for (int i = 0; i < 10; i++) printf("%lld\n", (tens[i] * inv[i]) % M);

    go(0);
    printf("%lld\n", ans);
}