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


int n, m;
int ans = 0;
const int CNT = 11;
const int pw[CNT] = {1, 7, 49, 343, 2401, 16807, 117649, 823543, 5764801, 40353607, 282475249};

int getsize(int x) {
    for (int i = CNT - 1; i >= 0; --i) 
        if (x > pw[i])
            return i + 1;
    return 1;
}
int k1, k2;
vector<int> cur;
void check() {
    int hh = 0;
    for (int i = 0; i < k1; ++i) 
        hh += pw[k1 - i - 1] * cur[i];
    int mm = 0;
    for (int i = k1; i < k1 + k2; ++i) 
        mm += pw[k1 + k2 - i - 1] * cur[i];
    // dbg2(hh, mm);
    ans += (hh < n && mm < m);
}

void gen(int k) {
    if (k == k1 + k2)
        check();
    else
        for (int i = 0; i < 7; ++i) {
            bool unused = true;
            for (int j = 0; j < k; ++j)
                if (cur[j] == i)
                    unused = false;
            if (unused) {
                cur[k] = i;
                gen(k + 1);
            } 
        }

}


int main() {

    cin >> n >> m;
    k1 = getsize(n), k2 = getsize(m);
    // dbg2(k1, k2);
    cur.resize(k1 + k2);

    gen(0); 

    cout << ans << '\n';


    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}