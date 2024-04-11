#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <ctime>
#include <functional>
#include <numeric>
#include <utility>

#include <cstdio>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

#include <bitset>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#define ff first
#define ss second
#define pb push_back
#define sqr(x) ((x) * (x))
#define countbits __builtin_popcountll
#define print(a)            cerr << (a) << '\n'
#define dbg(a)              cerr << #a << " = " << (a) << '\n'
#define dbg2(a, b)          cerr << #a << " = " << (a) << " " << #b << " = " << (b) << '\n'
#define dbg3(a, b, c)       cerr << #a << " = " << (a) << " " << #b << " = " << (b) << " " << #c << " = " << (c) << '\n'
#define dbg4(a, b, c, d)    cerr << #a << " = " << (a) << " " << #b << " = " << (b) << " " << #c << " = " << (c) << " " << #d << " = " << (d) << '\n'
#define dbg5(a, b, c, d, e) cerr << #a << " = " << (a) << " " << #b << " = " << (b) << " " << #c << " = " << (c) << " " << #d << " = " << (d) << " " << #e << " = " << (e) << '\n'
#define PI 3.1415926535897932384626433

using std::cerr;
using std::cin;
using std::cout;

using std::bitset;
using std::deque;
using std::map;
using std::pair;
using std::queue;
using std::set;
using std::string;
using std::vector;
using std::unordered_map;
using std::unordered_set;

using std::abs;
using std::max;
using std::min;

using std::sort;
using std::swap;

#define int ll
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pul;

struct init{
    init() {
        cin.tie(0);
        std::iostream::sync_with_stdio(0);
        cout << std::fixed << std::setprecision(10);
        cerr << std::fixed << std::setprecision(10);
        srand(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count()); 
    }
} init;
const int CNT = 64;
bool isparent(int v, int u) {
    bitset<CNT> a = v, b = u;
    int ftv = CNT - 1, ftu = CNT - 1;
    for (; ftv >= 0 && a[ftv] == 0; --ftv);
    for (; ftu >= 0 && b[ftu] == 0; --ftu);
    bool isparent = true;
    for (int i = 0; i <= ftv; ++i)    
        isparent &= a[i] == b[i + ftu - ftv];
    return isparent;
}
vector<pii> way(int v, int u) {
    vector<pii> ans;
    if (v > u) swap(v, u);
    int cur = v;
    while (!isparent(cur, u)) 
        cur >>= 1;  
    int cura = cur, prev;
    while (cura != v)   {
        prev = cura;
        cura <<= 1;
        int ano = cura | 1LL;
        if (isparent(ano, v)) {
            cura = ano;
        }
        ans.pb({cura, prev});
    }
    cura = cur;
    while (cura != u)   {
        prev = cura;
        cura <<= 1;
        int ano = cura | 1LL;
        if (isparent(ano, u)) {
            cura = ano;
        }
        ans.pb({cura, prev});
    }
    return std::move(ans);
}

int32_t main() {
    map<ll, map<ll, ll>> g;
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int type, v, u, w;
        cin >> type >> v >> u;
        auto t = way(v, u);
        if (type == 1) {
            cin >> w;
            for (pii p : t) {
                g[p.ff][p.ss] += w;
                g[p.ss][p.ff] += w;
            }
        } else {
            int ans = 0;
            for (pii p : t) {
                ans += g[p.ff][p.ss];
            }            
            cout << ans << '\n';
        }
    }


    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}