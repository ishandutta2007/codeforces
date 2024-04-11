#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <utility>
#include <stdint.h>
#include <assert.h>
#include <time.h>
#include <math.h>
#include <queue>
#include <deque>
#include <bitset>

#define ff first
#define ss second
#define pb push_back
#define sqr(x) ((x) * (x))
#define dbg(a)        cerr << #a << " = " << (a) << '\n'
#define dbg2(a, b)    cerr << #a << " = " << (a) << " " << #b << " = " << (b) << '\n'
#define dbg3(a, b, c) cerr << #a << " = " << (a) << " " << #b << " = " << (b) << " " << #c << " = " << (c) << '\n'

using std::cin;
using std::cout;
using std::cerr;

using std::pair;
using std::vector;
using std::map;
using std::unordered_map;
using std::set;
using std::unordered_set;
using std::queue;
using std::deque;
using std::bitset;

using std::max;
using std::min;
using std::abs;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void init() {
    std::iostream::sync_with_stdio(0);
    srand(time(NULL));
    cout << std::fixed;
    cout.precision(10);
    cerr << std::fixed;
    cerr.precision(10);
}

ull get(ull x) {
    if (x <= 1)
        return 0;
    bitset<64> a = x;
    int mx;
    for (int i = 63; i >= 0; --i) {
        mx = i;
        if (a[i])
            break;
    }
    ull ans = 0;

    for (int i = 0; i < mx; ++i) {
        ans += i;
    }

    int mx0 = -1;
    for (int i = 0; i < mx; ++i) {
        if (!a[i]) 
            mx0 = i;
    }
    if (mx0 != -1) {
        ans += mx - mx0 - 1;
        bool ok = true;
        for (int i = mx0 - 1; i >= 0; --i)
            ok &= a[i];
        if (ok)
            ++ans;
    } else
        ans += mx;

    return ans;
}

int main() {
    init();

    ull a, b;
    cin >> a >> b;
    cout << get(b) - get(a - 1) << '\n';
    
       
    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}