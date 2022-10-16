#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


int64_t can_take(int64_t S, int64_t W, int64_t CS, int64_t CW, int64_t P) {
    if (S > W)
        return can_take(W, S, CW, CS, P);

    if (S * CS >= P)
        return P / S;

    return CS + min((P - S * CS) / W, CW);
}

void run_case() {
    int64_t P, F, CS, CW, S, W;
    cin >> P >> F >> CS >> CW >> S >> W;
    int64_t best = 0;

    for (int64_t cs = 0; cs <= CS; cs++)
        if (cs * S <= P) {
            int64_t cw = min((P - cs * S) / W, CW);
            best = max(best, cs + cw + can_take(S, W, CS - cs, CW - cw, F));
        }

    cout << best << '\n';
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}