// #pragma GCC optimize("Ofast,unroll-all-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
// #pragma GCC target("popcnt")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;

#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
#define pb push_back
#define kek pop_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mp make_pair
// #define int ll


const int INF = (is_same<int, ll>::value ? 1e18 + 666 : 1e9 + 666);
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

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
inline bool cmin(t1 &a, const t2 &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class t1, class t2>
inline bool cmax(t1 &a, const t2 &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

inline int bpow(int a, int b, int mod) {
    int res = 1;
    for (; b; b >>= 1) {
        if (b & 1) {
            res *= a;
            res %= mod;
        }
        a *= a;
        a %= mod;
    }
    return res;
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
    // UseFiles("taskname");
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
}

typedef array<int, 2> Segment;
typedef array<Segment, 2> Rectangle;

Segment Intersect(const Segment& a, const Segment& b) {
    return {max(a[0], b[0]), min(a[1], b[1])};
}

Segment Unite(const Segment& a, const Segment& b) {
    if (a == Segment{-1, -1}) {
        return b;
    }
    assert(!(a[1] < b[0] || b[1] < a[0]));
    return {min(a[0], b[0]), max(a[1], b[1])};
}

bool Within(int x, const Segment& s) {
    return x >= s[0] && x <= s[1];
}

bool Within(const pii& point, const Rectangle& r) {
    return Within(point.first, r[0]) && Within(point.second, r[1]);
}

Rectangle Intersect(const Rectangle& a, const Rectangle& b) {
    return {Intersect(a[0], b[0]), Intersect(a[1], b[1])};
}

bool IsGood(const Segment& s) {
    return s[0] <= s[1];
}

bool IsGood(const Rectangle& r) {
    return IsGood(r[0]) && IsGood(r[1]);
}


void run() {
    int n, m;
    cin >> n >> m;
    vector<Rectangle> rects(n);
    vector<int> v(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        for (auto& [l, r] : rects[i]) {
            cin >> l >> r;
        }
    }

    vector<vector<Rectangle>> vars(n + 1);
    vars.back().pb(Rectangle{Segment{0, m}, Segment{0, m}});
    for (int i = n - 1; i > -1; --i) {
        Segment hor = {-1, -1}, vert = {-1, -1};
        for (auto rect : vars[i + 1]) {
            rect = Intersect(rect, rects[i]);
            if (!IsGood(rect)) continue;
            if (Within(v[i], rect[0])) {
                vert = Unite(vert, rect[1]);
            }
            if (Within(v[i], rect[1])) {
                hor = Unite(hor, rect[0]);
            }
        }

        if (hor != Segment{-1, -1}) {
            vars[i].pb(Rectangle{hor, Segment{0, m}});
        }
        if (vert != Segment{-1, -1}) {
            vars[i].pb(Rectangle{Segment{0, m}, vert});
        }
    }

    bool found = false;
    for (auto& rect : vars[0]) {
        if (Within({0, 0}, rect)) {
            cout << "Yes" << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "No" << endl;
        return;
    }
    int x = 0, y = 0;
    for (int i = 0; i < n; ++i) {
        found = false;
        if (Within({x, v[i]}, rects[i])) {
            for (auto& rect : vars[i + 1]) {
                if (Within({x, v[i]}, rect)) {
                    found = true;
                    break;
                }
            }
            if (found) {
                cout << 1 << " ";
                y = v[i];
                continue;
            }
        }
        assert(Within({v[i], y}, rects[i]));
        found = false;
        for (auto& rect : vars[i + 1]) {
            if (Within({v[i], y}, rect)) {
                found = true;
                break;
            }
        }
        assert(found);
        cout << 0 << " ";
        x = v[i];
    }
    cout << endl;
}