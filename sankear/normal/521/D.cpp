#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <deque>
#include <queue>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>
#include <complex>

#define pb push_back
#define pbk pop_back
#define sz(a) ((int) (a).size())
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define fs first
#define sc second
#define next _next
#define prev _prev
#define link _link
#define hash _hash

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

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int inf = 1e9;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = int(1e5) + 100;

struct tp {
    
    int num, add;
    ll a;
    
};

bool operator == (const tp& a, const tp& b) {
    return a.add * b.a == b.add * a.a && a.num == b.num;
}

bool operator < (const tp& a, const tp& b) {
    if (a.add * b.a != b.add * a.a) {
        return a.add * b.a > b.add * a.a;
    }
    return a.num < b.num;
}

bool is_set[N];
ll a[N];
pair<ll, int> mul[N];
ld sum_mul[N];
pii max_b[N];
vector<pii> add[N];
vi lst, best_lst;
set<tp> s;

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int k, n, m;
    cin >> k >> n >> m;
    for (int i = 0; i < k; ++i) {
        scanf(LLD, a + i);
    }
    int sz = 0;
    for (int i = 0; i < n; ++i) {
        int t, num, b;
        scanf("%d %d %d", &t, &num, &b);
        --num;
        if (t == 1) {
            is_set[i] = true;
            max_b[num] = max(max_b[num], mp(b, i));
        }
        if (t == 2) {
            add[num].pb(mp(b, i));
        }
        if (t == 3) {
            mul[sz++] = mp(b, i);
        }
    }
    sort(mul, mul + sz);
    reverse(mul, mul + sz);
    for (int i = 1; i <= sz; ++i) {
        sum_mul[i] = sum_mul[i - 1] + logl(mul[i - 1].fs);
    }
    for (int i = 0; i < k; ++i) {
        if (max_b[i].fs > a[i]) {
            add[i].pb(mp((int) (max_b[i].fs - a[i]), max_b[i].sc));
        }
        sort(all(add[i]));
        if (sz(add[i]) > 0) {
            s.insert({ i, add[i].back().fs, a[i] });
        }
    }
    ld cur = 0;
    pair<ld, int> ans(-1e100, -1);
    for (int i = 0; i < k; ++i) {
        cur += logl(a[i]);
    }
    for (int i = 0; i <= m; ++i) {
        if (i > 0 && sz(s) > 0) {
            tp best = *(s.begin());
            s.erase(s.begin());
            cur -= logl(best.a);
            cur += logl(best.a + best.add);
            a[best.num] += best.add;
            lst.pb(add[best.num].back().sc);
            add[best.num].pbk();
            if (sz(add[best.num]) > 0) {
                s.insert({ best.num, add[best.num].back().fs, a[best.num] });
            }
        }
        int can = min(m - i, sz);
        ans = max(ans, mp(cur + sum_mul[can], i));
    }
    int can = min(m - ans.sc, sz);
    for (int i = 0; i < min(ans.sc, sz(lst)); ++i) {
        if (is_set[lst[i]]) {
            best_lst.pb(lst[i]);
        }
    }
    for (int i = 0; i < min(ans.sc, sz(lst)); ++i) {
        if (!is_set[lst[i]]) {
            best_lst.pb(lst[i]);
        }
    }
    for (int i = 0; i < can; ++i) {
        best_lst.pb(mul[i].sc);
    }
    cout << sz(best_lst) << endl;
    for (int i = 0; i < sz(best_lst); ++i) {
        printf("%d ", best_lst[i] + 1);
    }
    puts("");
    return 0;
}