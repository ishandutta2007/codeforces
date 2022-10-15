#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <ctime>
#include <functional>
#include <numeric>
#include <utility>

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

#include <bitset>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#define ff first
#define ss second
#define pb push_back
#define sqr(x) ((x) * (x))
#define print(a)            cerr << (a) << '\n'
#define dbg(a)              cerr << #a << " = " << (a) << '\n'
#define dbg2(a, b)          cerr << #a << " = " << (a) << " " << #b << " = " << (b) << '\n'
#define dbg3(a, b, c)       cerr << #a << " = " << (a) << " " << #b << " = " << (b) << " " << #c << " = " << (c) << '\n'
#define dbg4(a, b, c, d)    cerr << #a << " = " << (a) << " " << #b << " = " << (b) << " " << #c << " = " << (c) << " " << #d << " = " << (d) << '\n'
#define dbg5(a, b, c, d, e) cerr << #a << " = " << (a) << " " << #b << " = " << (b) << " " << #c << " = " << (c) << " " << #d << " = " << (d) << " " << #e << " = " << (e) << '\n'

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
using std::tuple;
using std::vector;
using std::unordered_map;
using std::unordered_set;

using std::abs;
using std::max;
using std::min;
using std::swap;
using std::make_tuple;

typedef unsigned int uint;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct init{
    init() {
        cin.tie(0);
        cout.tie(0);
        std::iostream::sync_with_stdio(0);
        cout << std::fixed << std::setprecision(10);
        cerr << std::fixed << std::setprecision(10);
        srand(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count()); 
    }
} init;

void ask(int a, int b, int c, int d) {
    cout << "? " << a << ' ' << b << ' ' << c << ' ' << d << std::endl;
}

void check(int lx1, int ly1, int rx1, int ry1, int lx2, int ly2, int rx2, int ry2) {
    if (lx1 > rx1 || lx2 > rx2 || ly1 > ry1 || ly2 > ry2) return;
    int a, b;
    ask(lx1, ly1, rx1, ry1);
    cin >> a;
    if (a != 1) return;
    int t;
    if (lx1 < rx1) {
        ask(lx1 + 1, ly1, rx1, ry1);
        cin >> t;
        if (t) return;
        ask(lx1, ly1, rx1 - 1, ry1);
        cin >> t;
        if (t) return;
    }
    if (ly1 < ry1) {
        ask(lx1, ly1 + 1, rx1, ry1);
        cin >> t;
        if (t) return;
        ask(lx1, ly1, rx1, ry1 - 1);
        cin >> t;
        if (t) return;        
    }
    ask(lx2, ly2, rx2, ry2);
    cin >> b;
    if (b != 1) return;
    if (lx2 < rx2) {
        ask(lx2 + 1, ly2, rx2, ry2);
        cin >> t;
        if (t) return;
        ask(lx2, ly2, rx2 - 1, ry2);
        cin >> t;
        if (t) return;
    }
    if (ly2 < ry2) {
        ask(lx2, ly2 + 1, rx2, ry2);
        cin >> t;
        if (t) return;
        ask(lx2, ly2, rx2, ry2 - 1);
        cin >> t;
        if (t) return;        
    }
    cout << "! " << lx1 << ' ' << ly1 << ' ' << rx1 << ' ' << ry1 << ' ' << lx2 << ' ' << ly2 << ' ' << rx2 << ' ' << ry2 << std::endl;
    exit(0);
}


int main() {

    int n;
    cin >> n;
    int res;
    int lx1, ly1, rx1, ry1, lx2, ly2,  rx2, ry2;
    {
        int l = 0, r = n;
        while (r - l > 1) {
            int m = l + r >> 1;
            ask(1, 1, n, m);
            cin >> res;
            if (res == 2) r = m;
            else l = m;
        }
        ry1 = r;
    }
    {
        int l = 1, r = n + 1;
        while (r - l > 1) {
            int m = l + r >> 1;
            ask(1, m, n, n);
            cin >> res;
            if (res == 2) l = m;
            else r = m;
        }        
        ly1 = l;
    }

    {
        int l = 1, r = n + 1;
        while (r - l > 1) {
            int m = l + r >> 1;
            ask(1, m, n, n);
            cin >> res;
            if (res) l = m;
            else r = m;
        }        
        ly2 = l;
    }

    {
        int l = 1 - 1, r = n;
        while (r - l > 1) {
            int m = l + r >> 1;
            ask(1, 1, n, m);
            cin >> res;
            if (res) r = m;
            else l = m;
        }        
        ry2 = r;
    }

    dbg4(ly1, ry1, ly2, ry2);


    {
        int l = 0, r = n;
        while (r - l > 1) {
            int m = l + r >> 1;
            ask(1, 1, m, n);
            cin >> res;
            if (res == 2) r = m;
            else l = m;
        }
        rx1 = r;
    }
    {
        int l = 1, r = n + 1;
        while (r - l > 1) {
            int m = l + r >> 1;
            ask(m, 1, n, n);
            cin >> res;
            if (res == 2) l = m;
            else r = m;
        }
        lx1 = l;
    }
    {
        int l = 0, r = n;
        while (r - l > 1) {
            int m = l + r >> 1;
            ask(1, 1, m, n); 
            cin >> res;
            if (res) r = m;
            else l = m;
        }
        rx2 = r;
    }
    {
        int l = 1, r = n + 1;
        while (r - l > 1) {
            int m = l + r >> 1;
            ask(m, 1, n, n);
            cin >> res;
            if (res) l = m;
            else r = m;
        }
        lx2 = l;
    }

    dbg4(lx1, rx1, lx2, rx2);

    vector<int> xx = {lx1, rx1, lx2, rx2};
    sort(xx.begin(), xx.end());
    vector<int> yy = {ly1, ry1, ly2, ry2};
    sort(yy.begin(), yy.end());

    do {
        do {
            check(xx[0], yy[0], xx[1], yy[1], xx[2], yy[2], xx[3], yy[3]);
        } while (next_permutation(yy.begin(), yy.end()));
    }while (next_permutation(xx.begin(), xx.end()));


    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}