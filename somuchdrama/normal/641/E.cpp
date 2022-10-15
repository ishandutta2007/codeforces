#include <algorithm>
#include <assert.h>
#include <chrono>
#include <functional>
#include <numeric>
#include <math.h>
#include <memory.h>
#include <stdint.h>
#include <time.h>
#include <utility>

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdio.h>

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

void init() {
    std::iostream::sync_with_stdio(0);
    cout << std::fixed << std::setprecision(10);
    cerr << std::fixed << std::setprecision(10);
    srand(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count());
}

class SegmentTree
{
public:
    vector<ll> tree, flag;
    int n, sh;
    SegmentTree(){}
    SegmentTree(const vector<ll> & a) {
        n = a.size();
        sh = 1;
        while (sh < n)
            sh *= 2;
        tree.assign(sh + sh + 1, 0);
        flag.assign(sh + sh + 1, 0);
        for (int i = 0; i < n; ++i) 
            tree[i + sh] = a[i];
        for (int i = sh - 1; i > 0; --i) {
            flag[i] = 0;
            tree[i] = tree[i << 1] + tree[(i << 1) + 1];
        }
        --sh;
    }
    SegmentTree(const SegmentTree & other) {
        n = other.n;
        sh = other.n;
        tree = other.tree;
        flag = other.flag;
    }

    void push(int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] += flag[v];
            flag[v] = 0;
            return;
        }
        flag[v << 1] += flag[v];
        flag[(v << 1) + 1] += flag[v];
        tree[v] += flag[v] * (tr - tl + 1);
        flag[v] = 0;
    }

    ll get(int v, int tl, int tr, int l, int r) {
        if ((l > tr) || (r < tl))
            return 0;
        push(v, tl, tr);
        if ((l <= tl) && (tr <= r)) 
            return tree[v];
        int tm = (tl + tr) / 2;
        return get(v * 2, tl, tm, l, r) + get(v * 2 + 1, tm + 1, tr, l, r);
    }

    void add(int v, int tl, int tr, int l, int r, ll val) {
        push(v, tl, tr);
        if ((l > tr) || (r < tl))
            return;
        if ((l <= tl) && (tr <= r)) {
            flag[v] += val;
            push(v, tl, tr);
            return;
        }
        int tm = (tl + tr) / 2;
        add((v << 1), tl, tm, l, r, val);
        add((v << 1) + 1, tm + 1, tr, l, r, val);
        tree[v] = tree[v << 1] + tree[(v << 1) + 1];
    }
};

struct query{
	int type, t, x;
	query(){}
};
const int MAXN = 1e5;
query arr[MAXN];
SegmentTree tree[MAXN];
set<int> prep[MAXN];
int cnt[MAXN];
map<int, int> coord[MAXN];

int main() {
    init();

    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; ++i) {
    	cin >> arr[i].type >> arr[i].t >> arr[i].x;
    	s.insert(arr[i].x);
    }

    map<int, int> num;
    for (auto i : s) {
    	int sz = num.size();
    	num[i] = sz;
    }

    // for (auto i : num)
    // 	dbg2(i.ff, i.ss);

    int m = num.size();
    for (int i = 0; i < n; ++i) {
    	prep[num[arr[i].x]].insert(arr[i].t);
    }	

    for (int i = 0; i < m; ++i) {
    	for (auto j : prep[i]) {
    		int sz = coord[i].size();
    		coord[i][j] = sz;
    	}
    	cnt[i] = prep[i].size();
		tree[i] = SegmentTree(vector<ll>(cnt[i], 0));
		// for (auto j : coord[i])
		// 	dbg2(j.ff, j.ss);
    }

    for (int i = 0; i < n; ++i) {
    	int x = num[arr[i].x];
    	int t = coord[x][arr[i].t];
    	// dbg2(x, t);
    	if (arr[i].type == 1) {
    		tree[x].add(1, 0, tree[x].sh, t, tree[x].n - 1, +1);
    	} else if (arr[i].type == 2) {
    		tree[x].add(1, 0, tree[x].sh, t, tree[x].n - 1, -1);
    	} else {
    		cout << tree[x].get(1, 0, tree[x].sh, t, t) << '\n';
    	}
    }


    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}