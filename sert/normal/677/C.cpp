#include <bits/stdc++.h>
using namespace std;
const int N = 5000 + 4;
typedef long long ll;
typedef long double ld;
const ll md = 1e9 + 7;

ll step(ll a, ll st) {
    if (st == 0) return 1;
    if (st % 2) return (a * step(a, st - 1)) % md;
    ll q = step(a, st / 2);
    return (q * q) % md;
}

int main() {
    //freopen("a.in", "r", stdin);
    string s;
    cin >> s;
    ll ans = 0;
    for (char ch: s) {
        if ('0' <= ch && ch <= '9') ans += __builtin_popcount(ch - '0');
        if ('A' <= ch && ch <= 'Z') ans += __builtin_popcount(ch - 'A' + 10);
        if ('a' <= ch && ch <= 'z') ans += __builtin_popcount(ch - 'a' + 36);
        if (ch == '-') ans += 5;
        if (ch == '_') ans += 6;
    }
    cout << step(3, 6 * s.length() - ans);

    return 0;
}