#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
#define pb push_back
#define kek pop_back
#define pii pair<int, int>
#define mp make_pair
#define int ll

#define debug(x) cout << #x << " = " << x << endl;

const int INF = (is_same<int, ll>::value ? 1e18 + 666 : 1e9 + 666);

// const int MEM_SIZE = 5e8;
// char mem[MEM_SIZE];
// int cur_mem_ptr = 0;

// void* operator new(size_t n) {
//     cur_mem_ptr += n;
//     return mem + cur_mem_ptr - n;
// }

// void operator delete(void*) noexcept {}
// void operator delete(void*, size_t) noexcept {}

template<class t1, class t2>
bool cmin(t1 &a, const t2 &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class t1, class t2>
bool cmax(t1 &a, const t2 &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

#ifndef LOCAL
void UseFiles(const string &s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
#else
void UseFiles(const string&) {}
#endif

void run();

signed main() {
    // UseFiles("cowboys");
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
}

vector<vector<int>> divisors;
const int maxn = 2e5 + 666;

void init() {
    divisors.resize(maxn);
    for (int i = 1; i < maxn; ++i) {
        for (int j = i; j < maxn; j += i) {
            divisors[j].pb(i);
        }
    }
}

vector<vector<int>> get_cycles(const vector<int> &p, const vector<int> &c, int n) {
    vector<vector<int>> ans;
    vector<int> used(n, 0);
    for (int i = 0; i < n; ++i) {
        if (used[i]) {
            continue;
        }
        ans.emplace_back();
        int cur = i;
        while (!used[cur]) {
            used[cur] = 1;
            ans.back().pb(c[cur]);
            cur = p[cur];
        }
    }
    return ans;
}

bool check_cycle(const vector<int> &c, int start, int step) {
    for (int i = start + step; i < len(c); i += step) {
        if (c[i] != c[i - step]) {
            return false;
        }
    }
    return true;
}

bool check_cycle(const vector<int> &c, int step) {
    for (int start = 0; start < step; ++start) {
        if (check_cycle(c, start, step)) {
            return true;
        }
    }
    return false;
}

int get_min_period(const vector<int> &c) {
    int n = len(c);
    for (auto &x : divisors[n]) {
        if (check_cycle(c, x)) {
            return x;
        }
    }
    return -1;
}

void solve() {
    int n;
    cin >> n;
    vector<int> p(n), c(n);
    for (auto &x : p) {
        cin >> x;
        --x;
    }
    for (auto &x : c) {
        cin >> x;
    }
    int ans = INF;
    for (auto &x : get_cycles(p, c, n)) {
        cmin(ans, get_min_period(x));
    }
    cout << ans << endl;
}

void run() {
    init();
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}