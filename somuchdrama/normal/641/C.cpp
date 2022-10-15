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
    // std::iostream::sync_with_stdio(0);
    // cout << std::fixed << std::setprecision(10);
    // cerr << std::fixed << std::setprecision(10);
    srand(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count());
}

const int MAXN = 1e6;
int a[MAXN], b[MAXN];

int main() {
    init();

    for (int i = 0; i < MAXN; ++i) {
    	if (i & 1) a[i/2] = i+1;
    	else b[i/2] = i+1;
    }

    int n,q;
    scanf("%d %d", &n, &q);
    bool swapped = false;
    int even = 0, odd = 0;
    for (int i = 0; i < q; ++i) {
    	int type;
    	scanf("%d", &type);
    	if (type == 1) {
    		int x;
    		scanf("%d", &x);
    		if (x == 0) continue;
    		if (x < 0) x = n + x;
    		if (x & 1) {
    			swapped = swapped ^ 1;
    			if (!swapped) {
	    			--odd;
	    			odd += n/2;
	    			odd %= (n/2);
	    			--x;
    			} else {
	    			--even;
	    			even += n/2;
	    			even %= (n/2);
	    			--x;

    			}
    		}

    		even -= x/2;
    		even += n/2;
    		even %= (n/2);
    		odd -= x/2;
    		odd += n/2;
    		odd %= (n/2);

    	} else {
    		swapped = swapped ^ 1;
    	}
    	// dbg3(even, odd, swapped);
    }

    if (swapped) {
    	int p1 = odd, p2 = even;
    	for (int i = 1; i <= n; ++i) {
    		if (i & 1) {
    			int j = a[p2];
    			printf("%d ", j);
    			++p2;
    			p2 %= (n/2);
    		} else {
    			int j = b[p1];
    			printf("%d ", j);
    			++p1;
    			p1 %= (n/2);  			
    		}
    	}
	} else {
    	int p1 = odd, p2 = even;
    	for (int i = 1; i <= n; ++i) {
    		if ((i & 1) == 0) {
    			int j = a[p2];
    			printf("%d ", j);
    			++p2;
    			p2 %= (n/2);
    		} else {
    			int j = b[p1];
    			printf("%d ", j);
    			++p1;
    			p1 %= (n/2);  			
    		}
    	}
	}

	printf("\n");


    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}