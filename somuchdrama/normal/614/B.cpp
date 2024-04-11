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

const int MAXN = 1e5;
string arr[MAXN];

int main() {
    init();

    int n;
    cin >> n;
    int bad = -1;
    int zer = 0;
    bool was = false;
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
        int cnt = 0;
        bool ok = true;
        int cur = 0;
        for (int j = 0; j < arr[i].length(); ++j) {
            if (arr[i][j] == '1')
                ++cnt;
            if (arr[i][j] != '1' && arr[i][j] != '0')
                ok = false;
            if (arr[i][j] == '0')
                ++cur;
        }
        if (cnt > 1)
            ok = false;
        if (!ok)
            bad = i;
        if (ok)
            zer += cur;
        if (arr[i].length() == 1 && arr[i][0] == '0')
            was = true;
    }
    dbg3(was, zer, bad);
    if (was) {
        cout << "0\n";
        return 0;
    }
    if (bad == -1) {
        cout << "1";
        for (int i = 0; i < zer; ++i)
            cout << '0';
        cout << '\n';
        return 0;        
    }
    cout << arr[bad];
    for (int i = 0; i < zer; ++i)
        cout << '0';
    cout << '\n';
       
    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}