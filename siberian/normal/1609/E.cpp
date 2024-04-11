#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

const int B = 5;
const vector<string> subs = {"a", "b", "c", "ab", "bc"};

vector<pair<int, int>> good_masks[1 << B];

bool has(const string& s, const string& need) {
    int cur = 0;
    for (auto i : s) {
        if (cur == need.size()) return true;
        if (i == need[cur]) {
            ++cur;
        }
    }
    return cur == need.size();
}

bool check(const string& s, int& nextMask) {
    // cerr << "string s = " << s << endl;
    if (has(s, "abc")) {
        return false;
    }
    for (int i = 0; i < B; ++i) {
        if (has(s, subs[i])) {
            nextMask |= (1 << i);
        }
    }
    return true;
}

bool check(int maskL, int maskR, int& nextMask) {
    nextMask = maskL | maskR;
    for (int bitL = 0; bitL < B; ++bitL) {
        if (!((maskL >> bitL) & 1)) continue;
        for (int bitR = 0; bitR < B; ++bitR) {
            if (!((maskR >> bitR) & 1)) continue;
            if (!check(subs[bitL] + subs[bitR], nextMask)) {
                return false;
            }
        }
    }
    return true;
}

void precalc() {
    for (int maskL = 0; maskL < (1 << B); ++maskL) {
        for (int maskR = 0; maskR < (1 << B); ++maskR) {
            int nextMask = 0;
            if (check(maskL, maskR, nextMask)) {
                good_masks[nextMask].push_back({maskL, maskR});
            }
        }
    }
    int sum = 0;
    for (int mask = 0; mask < (1 << B); ++mask) {
        // cerr << "mask = " << mask << " sz = " << good_masks[mask].size() << endl;
        sum += good_masks[mask].size();
    }
    // cerr << "sum = " << sum << endl;
}

const int N = 1e5 + 10;
int n, q;
string s;

namespace SegmentTree{
    const int INF = 1e9 + 228;
    int tree[4 * N][1 << B];
    int pos[N];

    void merge(int v) {
        int vl = v * 2;
        int vr = v * 2 + 1;
        for (int mask = 0; mask < (1 << B); ++mask) {
            int cur = INF;
            for (int i = 0; i < good_masks[mask].size(); ++i) {
                chkmin(cur, tree[vl][good_masks[mask][i].first] + tree[vr][good_masks[mask][i].second]);
            }
            tree[v][mask] = cur;
        }
    }

    void init(int v, char c) {
        fill(tree[v], tree[v] + (1 << B), INF);
        if (c == 'a') {
            tree[v][1 << 0] = 0;
            tree[v][1 << 1] = 1;
            tree[v][1 << 2] = 1;
        } else if (c == 'b') {
            tree[v][1 << 0] = 1;
            tree[v][1 << 1] = 0;
            tree[v][1 << 2] = 1;
        } else {
            tree[v][1 << 0] = 1;
            tree[v][1 << 1] = 1;
            tree[v][1 << 2] = 0;
        }
    } 

    void build(int v, int tl, int tr) {
        if (tl >= tr) return;
        if (tl == tr - 1) {
            pos[tl] = v;
            init(v, s[tl]);
        } else {
            int tm = (tl + tr) / 2;
            build(v * 2, tl, tm);
            build(v * 2 + 1, tm, tr);
            merge(v); 
        }
    }

    void build() {
        build(1, 0, n);
    }

    void upd(int p, char c) {
        int v = pos[p];
        init(v, c);
        v /= 2;
        while (v) {
            merge(v);
            v /= 2;
        }
    } 

    int getAns() {
        return *min_element(tree[1], tree[1] + (1 << B));
    }

    string printMask(int mask) {
        string ans;
        for (int bit = 0; bit < B; ++bit) {
            ans += '0'+ ((mask >> bit) & 1);
        }
        return ans;
    }

    void print(int v, int tl, int tr) {
        cerr << "v = " << v << " tl = " << tl << " tr = " << tr << endl;
        for (int mask = 0; mask < (1 << B); ++mask) {
            // int cur = tree[v][mask];
            // cerr << (cur != INF ? cur : -1) << " ";
            if (tree[v][mask] == 0) {
                cerr << "mask = " << printMask(mask) << endl;
            }
        }
        cerr << endl;
        if (tl == tr - 1) return;
        int tm = (tl + tr) / 2;
        print(v * 2, tl, tm);
        print(v * 2 + 1, tm, tr);
    }

    void print() {
        print(1, 0, n);
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    precalc();
    cin >> n >> q >> s;
    SegmentTree::build();
    // SegmentTree::print();
    while (q--) {
        int pos;
        char x;
        cin >> pos >> x;
        --pos;
        SegmentTree::upd(pos, x);
        cout << SegmentTree::getAns() << '\n';
    }
    return 0;
}