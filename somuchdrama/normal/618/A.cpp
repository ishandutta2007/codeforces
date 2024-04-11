#include <algorithm>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include <utility>

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
#define dbg(a)        cerr << #a << " = " << (a) << '\n'
#define dbg2(a, b)    cerr << #a << " = " << (a) << " " << #b << " = " << (b) << '\n'
#define dbg3(a, b, c) cerr << #a << " = " << (a) << " " << #b << " = " << (b) << " " << #c << " = " << (c) << '\n'

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
typedef unsigned short ushort;
typedef pair<int, int> pii;
typedef pair<short, short> pss;
typedef pair<ushort, ushort> pus;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pul;

void init() {
    std::iostream::sync_with_stdio(0);
    cout << std::fixed;
    cout.precision(10);
    cerr << std::fixed;
    cerr.precision(10);
    srand(time(0));
}

int main() {
    init();

    int n;
    cin >> n;
    vector<int> a(n, 1);
    vector<int> b(n, 1);
    int cnt = 0;
    while (a != b || !cnt) {
        ++cnt;
        a = b;
        b.clear();
        bool last = false;
        for (int i = 0; i < a.size() - 1; ++i) {
            if (a[i] == a[i + 1]) {
                if (i == a.size() - 2)
                    last = true;
                b.pb(a[i] + 1);
                ++i;
            } else {
                b.pb(a[i]);
            }
        }
        if (!last)
            b.pb(a.back());
    }

    for (auto i : b) {
        cout << i << ' ';
    }
    cout << '\n';


    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}