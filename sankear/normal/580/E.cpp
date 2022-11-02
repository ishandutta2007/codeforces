#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <complex>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

#define pb push_back
#define mp make_pair
#define pbk pop_back
#define all(x) (x).begin(), (x).end()
#define sz(s) ((int) (s).size())
#define fs first
#define sc second
#define prev _prev
#define next _next
#define rank _rank
#define hash _hash
#define left _left
#define right _right

#if _WIN32 || __WIN32__ || _WIN64 || __WIN64__
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

const int inf = 1e9;
const double pi = 4 * atan(1.0);
const double eps = 1e-9;
const int N = int(1e5) + 100;
const int X1 = 4243;
const int MOD1 = int(1e9) + 7;
const int X2 = 10007;
const int MOD2 = 42424243;

struct hash {
    
    int a, b;
    
    hash() : a(0), b(0) {}
    
    hash(int a) : a(a), b(a) {}
    
    hash(int a, int b) : a(a), b(b) {}
    
};

hash operator + (const hash& a, const hash& b) {
    hash c(a.a + b.a, a.b + b.b);
    if (c.a >= MOD1) {
        c.a -= MOD1;
    }
    if (c.b >= MOD2) {
        c.b -= MOD2;
    }
    return c;
}

hash operator - (const hash& a, const hash& b) {
    hash c(a.a - b.a, a.b - b.b);
    if (c.a < 0) {
        c.a += MOD1;
    }
    if (c.b < 0) {
        c.b += MOD2;
    }
    return c;
}

hash operator * (const hash& a, const hash& b) {
    return hash((1LL * a.a * b.a) % MOD1, (1LL * a.b * b.b) % MOD2);
}

bool operator == (const hash& a, const hash& b) {
    return a.a == b.a && a.b == b.b;
}

const hash X(X1, X2);

struct tr {
    
    bool need;
    int c, l, r;
    hash h;
    
};

int maxv;
char s[N];
tr rmq[4 * N];
hash pw[4 * N], sum_pw[4 * N];

inline void init() {
    pw[0] = 1;
    for (int i = 1; i < 4 * N; ++i) {
        pw[i] = pw[i - 1] * X;
    }
    for (int i = 0; i < 4 * N; ++i) {
        sum_pw[i] = (i > 0 ? sum_pw[i - 1] : 0) + pw[i];
    }
}

inline void calc(int v) {
    rmq[v].h = rmq[v * 2].h * pw[rmq[v * 2].r - rmq[v * 2].l + 1] + rmq[v * 2 + 1].h;
}

inline void push(int v) {
    if (!rmq[v].need) {
        return;
    }
    rmq[v].h = sum_pw[rmq[v].r - rmq[v].l] * (rmq[v].c + 1);
    if (v < maxv) {
        rmq[v * 2].need = rmq[v * 2 + 1].need = true;
        rmq[v * 2].c = rmq[v * 2 + 1].c = rmq[v].c;
    }
    rmq[v].need = false;
}

void update(int v, int l, int r, int c) {
    push(v);
    if (rmq[v].l > r || rmq[v].r < l) {
        return;
    }
    if (rmq[v].l >= l && rmq[v].r <= r) {
        rmq[v].need = true;
        rmq[v].c = c;
        push(v);
        return;
    }
    update(v * 2, l, r, c);
    update(v * 2 + 1, l, r, c);
    calc(v);
}

inline pair<hash, int> merge(pair<hash, int> a, pair<hash, int> b) {
    return mp(a.fs * pw[b.sc] + b.fs, a.sc + b.sc);
}

pair<hash, int> get_h(int v, int l, int r) {
    push(v);
    if (rmq[v].l > r || rmq[v].r < l) {
        return mp(0, 0);
    }
    if (rmq[v].l >= l && rmq[v].r <= r) {
        return mp(rmq[v].h, rmq[v].r - rmq[v].l + 1);
    }
    return merge(get_h(v * 2, l, r), get_h(v * 2 + 1, l, r));
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    init();
    int n, m, k;
    cin >> n >> m >> k;
    scanf("%s", s);
    maxv = 1;
    while (maxv < n) {
        maxv *= 2;
    }
    for (int i = 0; i < maxv; ++i) {
        rmq[i + maxv].l = rmq[i + maxv].r = i;
    }
    for (int i = maxv - 1; i > 0; --i) {
        rmq[i].l = rmq[i * 2].l;
        rmq[i].r = rmq[i * 2 + 1].r;
    }
    for (int i = 0; i < n; ++i) {
        rmq[i + maxv].h = s[i] - '0' + 1;
    }
    for (int i = maxv - 1; i > 0; --i) {
        calc(i);
    }
    for (int i = 0; i < m + k; ++i) {
        int t, l, r, c;
        scanf("%d %d %d %d", &t, &l, &r, &c);
        --l;
        --r;
        if (t == 1) {
            update(1, l, r, c);
            continue;
        }
        pair<hash, int> a = get_h(1, l, r - c);
        pair<hash, int> b = get_h(1, l + c, r);
        if (a == b) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}