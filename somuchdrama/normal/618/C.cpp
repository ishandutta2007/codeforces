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
struct point
{
    double x, y;
    point() {}
    point(double x, double y): x(x), y(y) {}
};

std::istream & operator >>(std::istream& is, point & p) {
    return is >> p.x >> p.y;
}

struct vc
{
    double x, y;
    vc() {}
    vc(double x, double y): x(x), y(y) {}
    vc(point a, point b) {
        x = b.x - a.x;
        y = b.y - a.y;
    }
};

double operator %(vc a, vc b) {
    return a.x * b.y - a.y * b.x;
}

int main() {
    init();

    int n;
    cin >> n;
    vector<point> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    int a = 0, b = 1, c = -1;
    for (int i = 2; i < n; ++i) {
        vc AB(arr[a], arr[b]), BI(arr[b], arr[i]);
        if (AB % BI != 0) {
            c = i;
            if (AB % BI < 0)
                swap(b, c);
            break;
        }
    }

    for (int i = 2; i < n; ++i) {
        if (i == c) continue;
        vc AB(arr[a], arr[b]), BC(arr[b], arr[c]), CA(arr[c], arr[a]), AI(arr[a], arr[i]), BI(arr[b], arr[i]), CI(arr[c], arr[i]);
        if (AB % AI >= 0 && BC % BI >= 0 && CA % CI >= 0) {
            if (AB % BI != 0) {
                c = i;
                continue;
            }
            if (CA % AI != 0) {
                b = i;
                continue;
            }
            if (BC % CI != 0) {
                a = i;
                continue;
            }
        }
    }

    cout << a+1 << ' ' << b+1 << ' ' << c+1 << '\n';

    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}