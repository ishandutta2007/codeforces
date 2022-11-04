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

template<template<class T> class cmp>
struct ShiftQueue {
    int top() const {
        return q.top() + shift;
    }

    void push(int val) {
        q.push(val - shift);
    }

    void pop() {
        q.pop();
    }

    size_t size() const {
        return q.size();
    }

    bool empty() const {
        return q.empty();
    }

    priority_queue<int, vector<int>, cmp<int>> q;
    int shift;
};

template<class Q1, class Q2>
void Balance(Q1& q1, Q2& q2) {
    while (q1.top() > q2.top()) {
        q2.push(q1.top());
        q1.pop();
        q1.push(q2.top());
        q2.pop();
    }
    assert(q1.size() == q2.size());
}

void run() {
    int n;
    cin >> n;
    vector<pii> points(n);
    for (auto& [x, y] : points) {
        cin >> x >> y;
    }
    map<int, vector<int>> diags;
    for (auto& [x, y] : points) {
        diags[x + y].pb(x);
    }
    priority_queue<int> l;
    ShiftQueue<greater> r;
    int s = 0, lastCrd = 0;
    ll compensation = 0;
    for (auto& [c, pts] : diags) {
        compensation += 1ll * s * (c - lastCrd);
        r.shift += c - lastCrd;
        for (auto& x : pts) {
            l.push(x);
            r.push(x);
        }
        Balance(l, r);
        lastCrd = c;
        s += len(pts);
    }
    ll ans = 0;
    const int med = l.top();
    while (!l.empty()) {
        ans += med - l.top();
        l.pop();
    }
    while (!r.empty()) {
        ans += r.top() - med;
        r.pop();
    }
    ans -= compensation;
    assert(ans >= 0);
    assert(ans % 2 == 0);
    cout << (ans >> 1) << endl;
}