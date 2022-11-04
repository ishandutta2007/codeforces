// #pragma GCC optimize("Ofast,unroll-all-loops")

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

// const int MEM_SIZE = 1e8;
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
    // UseFiles("squads");
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
}

vector<int> try_solve(int n, const vector<vector<int>> &p, vector<int> appear, const vector<vector<int>> &back_ind, int idx) {
    vector<int> res;
    vector<int> new_elems(n - 1);
    for (int i = 0; i < len(new_elems); ++i) {
        new_elems[i] = len(p[i]);
    }
    priority_queue<pii, vector<pii>, greater<pii>> candidates;
    vector<int> used(n - 1, 0), in_ans(n, 0);
    candidates.push({new_elems[idx], idx});
    while (len(candidates)) {
        auto [cnt, id] = candidates.top();
        candidates.pop();
        if (new_elems[id] != cnt || used[id]) {
            continue;
        }

        if (cnt == 0) {
            return {};
        }

        used[id] = 1;
        vector<int> add;
        for (auto &x : p[id]) {
            if (!in_ans[x]) {
                add.pb(x);
            }
        }
        sort(all(add), [&appear](int a, int b) {
            return appear[a] < appear[b];
        });
        for (auto &x : add) {
            res.pb(x);
        }
        vector<int> check(res.end() - len(p[id]), res.end());
        sort(all(check));
        if (check != p[id]) {
            return {};
        }
        for (auto &x : add) {
            --appear[x];
            in_ans[x] = 1;
            for (auto &y : back_ind[x]) {
                if (used[y]) {
                    continue;
                }
                --new_elems[y];
                candidates.push({new_elems[y], y});
            }
        }
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> p(n - 1);
    vector<int> appear(n, 0);
    for (auto &x : p) {
        int ln;
        cin >> ln;
        x.resize(ln);
        for (auto &val : x) {
            cin >> val;
            --val;
            ++appear[val];
        }
    }
    vector<vector<int>> back_ind(n);
    for (int i = 0; i < n - 1; ++i) {
        for (auto &x : p[i]) {
            back_ind[x].pb(i);
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        if (len(p[i]) == 2) {
            if (auto ans = try_solve(n, p, appear, back_ind, i); len(ans) != 0) {
                assert(len(ans) == n);
                for (auto &x : ans) {
                    cout << x + 1 << " ";
                }
                cout << endl;
                return;
            }
        }
    }
    assert(false);
}

void run() {
    int n;
    cin >> n;
    while (n --> 0) {
        solve();
    }
}