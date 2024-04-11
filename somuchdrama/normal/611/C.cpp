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

const int MAXN = 502;
char arr[MAXN][MAXN];
int cnthor[MAXN][MAXN];
int cntver[MAXN][MAXN];
int gethor[MAXN][MAXN];
int getver[MAXN][MAXN];

int main() {
    init();

    int h, w;
    cin >> h >> w;
    for (int i = 1; i <= h; ++i)
        for (int j = 1; j <= w; ++j)
            cin >> arr[i][j];

    for (int i = 0; i <= h + 1; ++i) {
        arr[i][0] = arr[i][w + 1] = '#';
        gethor[i][0] = 0;
        getver[i][0] = 0;
    }
    for (int i = 0; i <= w + 1; ++i) {
        arr[0][i] = arr[h + 1][i] = '#';
        gethor[0][i] = 0;
        getver[0][i] = 0;
    }

    for (int i = 1; i <= h; ++i)
        for (int j = 1; j <= w; ++j) {
            if (arr[i][j] == '#')
                continue;
            if (arr[i][j - 1] == '.')
                cnthor[i][j] = 1;
            if (arr[i - 1][j] == '.')
                cntver[i][j] = 1;
        }

    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            gethor[i][j] = gethor[i - 1][j] + gethor[i][j - 1] - gethor[i - 1][j - 1] + cnthor[i][j];
            getver[i][j] = getver[i - 1][j] + getver[i][j - 1] - getver[i - 1][j - 1] + cntver[i][j];
        }
    }

    int q;
    cin >> q;
    for (int t = 0; t < q; ++t) {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        cout << (gethor[rx][ry] + gethor[lx - 1][ly] - gethor[rx][ly] - gethor[lx - 1][ry]) +
                 (getver[rx][ry] + getver[lx][ly - 1] - getver[rx][ly - 1] - getver[lx][ry]) << '\n';
    }
    
       
    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}