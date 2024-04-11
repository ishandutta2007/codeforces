#include <iomanip>
#include <iostream>
#include <sstream>

#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <ctime>
#include <functional>
#include <numeric>

#define ff first
#define ss second
#define pb push_back
#define sqr(x) ((x) * (x))
#define nav(a) #a, '=', a

using std::cerr;
using std::cin;
using std::cout;

using std::bitset;
using std::map;
using std::pair;
using std::queue;
using std::set;
using std::string;
using std::tuple;
using std::vector;
using std::unordered_map;
using std::unordered_set;

using std::abs;
using std::min;
using std::max;

using std::swap;
using std::make_tuple;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<typename T> void scan(T&x) {cin >> x;}
template<typename T, typename...Ts> void scan(T&x, Ts&...xs) {
    scan(x);
    scan(xs...);
}

template<typename T> void print(T x) {cout << x << '\n';}
template<typename T, typename...Ts> void print(T x, Ts...xs) {
    cout << x << ' ';
    print(xs...);
}

template<typename T> void dbg(T x) {cerr << x << '\n';}
template<typename T, typename...Ts> void dbg(T x, Ts...xs) {
    cerr << x << ' ';
    dbg(xs...);
}

struct init{
    init() {
        cin.tie(0);
        std::iostream::sync_with_stdio(0);
        cout << std::fixed << std::setprecision(10);
        cerr << std::fixed << std::setprecision(10);
        using namespace std::chrono;
        srand(duration_cast<nanoseconds>(high_resolution_clock::now().time_since_epoch()).count()); 
    }
    ~init() {
        dbg("Time elapsed:", 1.0 * clock() / CLOCKS_PER_SEC, "s.");
    }
} init;


int main() {
    int n, m;
    scan(n, m);
    vector<int> a(n);
    for (int & i : a)
        scan(i);

    for (int ans = n; ans >= 0; --ans) {
        vector<vector<int>> small(m + 2);
        map<int, vector<int>> big;
        for (int pos = 0; pos < n; ++pos) {
            int i = a[pos];
            if (i <= m) 
                small[i].pb(pos);
            else 
                big[i].pb(pos);
        }
        int ptr = 1;
        int changes = 0;
        for (auto & p : big) {
            while (p.ss.size()) {
                while (small[ptr].size() >= ans && ptr <= m)
                    ++ptr;
                if (ptr > m) 
                    break;
                small[ptr].pb(p.ss.back());
                p.ss.pop_back();
                ++changes;
            }
        }
        for (int i = 1; i <= m; ++i) {
            while (small[i].size() > ans) {
                while (small[ptr].size() >= ans && ptr <= m)
                    ++ptr;
                if (ptr > m) 
                    break;
                small[ptr].pb(small[i].back());
                small[i].pop_back();
                ++changes;
            }
        }
        bool ok = true;
        for (int i = 1; i <= m; ++i)
            ok &= (small[i].size() >= ans);
        if (ok) {
            print(ans, changes);
            vector<int> b(n);
            for (int i = 1; i <= m; ++i) {
                for (int j : small[i])
                    b[j] = i;
            }
            for (auto p : big)
                for (int j : p.ss)
                    b[j] = p.ff;
            for (int i : b)
                cout << i << ' ';
            print("");
            break;
        }
    }



    return 0;
}