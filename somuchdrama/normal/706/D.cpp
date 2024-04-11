#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
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

const int ALP = 2, MAXN = 1e5, MAXB = 30;

struct node {
    int term = 0;
    node * go[ALP]; // or map<char, node *> go;
    node() {}
} trie[MAXN * MAXB];

int firstfree = 1;

void insert(uint s) {
    node * v = trie;
    for (int i = MAXB - 1; i >= 0; --i) {
        int j = ((1u << i) & s) >> i;
        if (!v->go[j])
            v->go[j] = &trie[firstfree++];
        v = v->go[j];
        ++(v->term);
    }
}
void erase(uint s) {
    node * v = trie;
    node * prev = trie;
    for (int i = MAXB - 1; i >= 0; --i) {
        int j = ((1u << i) & s) >> i;
        if (!v->go[j])
            v->go[j] = &trie[firstfree++];
        prev = v;
        v = v->go[j];
        --(v->term);
        if (v->term == 0) 
            prev->go[j] = nullptr;
    }
}

uint get(uint s) {
    node * v = trie;
    uint ans = 0;
    for (int i = MAXB - 1; i >= 0; --i) {
        int j = (((1u << i) & s) >> i) ^ 1;
        if (!v->go[j])
            j ^= 1;
        ans |= (1u << i) * j;
        v = v->go[j];
    }    
    return ans;
}

int main() {
    insert(0);
    int q;  
    cin >> q;
    while (q--) {
        char c;
        uint x;
        cin >> c >> x;
        if (c == '+') insert(x);
        if (c == '-') erase(x);
        if (c == '?') cout << (x ^ get(x)) << '\n';
    }

    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}