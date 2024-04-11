#include <algorithm>
#include <assert.h>
#include <chrono>
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
    srand(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count());
}
struct point{
    double x, y;
    point(){}
    point(double x, double y): x(x), y(y){}
};
const int MAXN = 1e5;
point arr[MAXN + 1];

double dist(point a, point b) {
    return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}
std::istream & operator >>(std::istream& is, point & p) {
    return is >> p.x >> p.y;
}
const double pi = 3.141592653589;
double s(double r) {
    return pi * r * r;
}
struct vc{
    double x, y;
    vc(point a, point b){
        x = b.x - a.x;
        y = b.y - a.y;
    }
};

double scal(vc a, vc b){
    return a.x * b.x + a.y * b.y;
}
double vect(vc a, vc b){
    return a.x * b.y - a.y * b.x;
}
double po(point a, point b, point c) {
    vc CA(c, a), CB(c, b), AC(a, c), AB(a, b), BA(b, a), BC(b, c);
    double high = abs(vect(CA, CB) / dist(a, b));

    if (scal(AC, AB) < 0) return dist(c, a);
    else if (scal(BA, BC) < 0) return dist(c, b);
    else return high;
}
int main() {
    init();

    int n;
    point p;
    cin >> n >> p;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    arr[n] = arr[0];
    double mn = 1e9, mx = -1;
    for (int i = 0; i < n; ++i) {
        mn = min(mn, po(arr[i], arr[i + 1], p));
        mx = max(mx, dist(p, arr[i]));
    }

    cout << s(mx) - s(mn) << '\n';
    
       
    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}