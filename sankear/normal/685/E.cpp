#pragma comment(linker, "/STACK:256000000")

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#undef NDEBUG
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <tuple>

using namespace std;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pbk pop_back
#define sz(s) ((int) (s).size())
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif
#if _WIN32 || __WIN32__ || _WIN64 || __WIN64__
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define prev huprev
#define next hunext
#define link hulink
#define hash huhash
#define rank hurank
#define y0 yy0
#define y1 yy1

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = 1e9;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = 1010;
const int M = int(2e5) + 100;

struct query {
    
    int from, to, num;
    
};

vi lst[N];
int a[M], b[M];
bool ans[M];
bitset<N> vers[M];
vector<query> qs[N];
vi g[M], rg[M];

void solve(int l, int r, const vector<query>& qs) {
    if (l >= r) {
        return;
    }
    int mid = (l + r) / 2;
    vector<query> nqs;
    for (const query& q : qs) {
        if (q.to <= mid) {
            nqs.pb(q);
        }
    }
    solve(l, mid, nqs);
    nqs.clear();
    for (const query& q : qs) {
        if (q.from > mid) {
            nqs.pb(q);
        }
    }
    solve(mid + 1, r, nqs);
    for (int i = l; i <= r; ++i) {
        vers[i].reset();
    }
    for (int i = mid; i >= l; --i) {
        vers[i].set(a[i]);
        vers[i].set(b[i]);
        for (int j : g[i]) {
            if (j <= mid) {
                vers[i] |= vers[j];
            }
        }
    }
    for (int i = mid + 1; i <= r; ++i) {
        vers[i].set(a[i]);
        vers[i].set(b[i]);
        for (int j : rg[i]) {
            if (j > mid) {
                vers[i] |= vers[j];
            }
        }
    }
    for (const query& q : qs) {
        if (q.from <= mid && q.to > mid) {
            ans[q.num] = (vers[q.from] & vers[q.to]).any();
        }
    }
}

int main() {
    cerr << sizeof(vers) / 1024 / 1024 << endl;
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m, qq;
    cin >> n >> m >> qq;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", a + i, b + i);
        --a[i];
        --b[i];
        lst[a[i]].pb(i);
        lst[b[i]].pb(i);
    }
    for (int i = 0; i < n; ++i) {
        sort(all(lst[i]));
        for (int j = 0; j + 1 < sz(lst[i]); ++j) {
            g[lst[i][j]].pb(lst[i][j + 1]);
            rg[lst[i][j + 1]].pb(lst[i][j]);
        }
    }
    vector<query> qs;
    for (int i = 0; i < qq; ++i) {
        int s, t, l, r;
        scanf("%d %d %d %d", &l, &r, &s, &t);
        --l;
        --r;
        --s;
        --t;
        int spos = lower_bound(all(lst[s]), l) - lst[s].begin();
        if (spos >= sz(lst[s])) {
            continue;
        }
        int tpos = upper_bound(all(lst[t]), r) - lst[t].begin() - 1;
        if (tpos < 0) {
            continue;
        }
        query q;
        q.num = i;
        q.from = lst[s][spos];
        q.to = lst[t][tpos];
        if (q.from > q.to) {
            continue;
        }
        if (q.from == q.to) {
            ans[q.num] = true;
            continue;
        }
        qs.pb(q);
    }
    solve(0, m - 1, qs);
    for (int i = 0; i < qq; ++i) {
        puts((ans[i] ? "Yes" : "No"));
    }
    return 0;
}