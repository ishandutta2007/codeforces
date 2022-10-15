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

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
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

string tos(int x) {
    string ans;
    if (!x) return "0";
    while (x) {
        ans += x % 10 + '0';
        x /= 10;
    }
    std::reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    string t, ans;
    int useless, zeros;
    for (useless = 0; useless < n && s[useless] == '0'; ++useless);
    for (int i = useless; i < n; ++i)
        t.pb(s[i]);

    int m = t.length();
    for (zeros = m - 1; zeros >= 0 && t[zeros] == '0'; --zeros);

    int pt;
    for (pt = 0; pt < m && t[pt] != '.'; ++pt);
    if (pt == m) {
        ans += t[0];
        if (zeros > 0) {
            ans += '.';
            for (int i = 1; i <= zeros; ++i)
                ans += t[i];
        }
        if (m > 1) {
            ans += 'E';
            ans += tos(m - 1);
        }
    } else {
        if (pt == 0) {
            int ft = 1;
            for (; t[ft] == '0'; ++ft);
            ans += t[ft];
            if (zeros > ft) {
                ans += '.';
                for (int i = ft + 1; i <= zeros; ++i) ans += t[i];
            }
            ans += "E-";
            ans += tos(ft);
        } else {
            ans += t[0];
            bool interes = false;
            for (int i = 1; i < m; ++i)
                interes |= (t[i] != '0' && t[i] != '.');
            if (interes) {
                ans += '.';
                int lz = pt - 1;
                if (zeros == pt) {
                    for (; lz >= 0 && t[lz] == '0'; --lz);
                    zeros = lz;
                }
                for (int i = 1; i <= zeros; ++i)
                    if (t[i] != '.')
                        ans += t[i];
            }
            int E = pt - 1;
            if (E) {
                ans += 'E';
                ans += tos(E);
            }
        }
    }


    cout << ans << '\n';


    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}