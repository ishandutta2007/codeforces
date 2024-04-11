#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pli = pair<li, li>;

const int INF = 2e9 + 13;
const li INF64 = 1e18 + 13;
const int M = 998244353;
const int N = 2e5 + 13;

/*
1
1 1
*/

map<pair<pair<pli, pli>, bool>, li> mem;

li calc(pli a, bool inva, pli b, bool invb) {
//    cout << "calc " << a.f << ' ' << a.s << ' ' << b.f << ' ' << b.s  << inva << ' ' << invb << endl;
    if(a.f > b.f) {
        swap(a, b);
        swap(inva, invb);
    }

    if(inva) {
        inva ^= 1;
        invb ^= 1;
    }

    if(a.f == b.f)
        return (inva != invb ? a.s - a.f : 0ll);

    if(mem.count({{a, b}, invb}))
        return mem[{{a, b}, invb}];

    for(li k = 1; ; k <<= 1) {
        if(k * 2 > b.f) {
            if(k * 2 >= b.s)
                return mem[{{a, b}, invb}] = calc(a, inva, pli(b.f - k, b.s - k), invb ^ 1);
            else {
                li len = k * 2 - b.f;
                return mem[{{a, b}, invb}] = calc(pli(a.f, a.f + len), inva, pli(b.f - k, b.f - k + len), invb ^ 1) +
                        calc(pli(a.f + len, a.s), inva, pli(b.f + len, b.s), invb);
            }
        }
    }
}

void solve() {
    li n, m;
    cin >> n >> m;

    cout << calc(pli(0, m), false, pli(n, n + m), false) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--) {
        solve();
    }
}