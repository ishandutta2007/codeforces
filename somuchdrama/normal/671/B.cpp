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
    cin.tie(0);
    cout << std::fixed << std::setprecision(10);
    cerr << std::fixed << std::setprecision(10);
    srand(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count());
}

const int MAXN = 5e5;
ll arr[MAXN];


int main() {
    init();

    int n; ll k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> arr[i];

    if (n == 1) {
    	puts("0");
    	return 0;
    }
	
    ll mxel;
    ll mn = *(std::min_element(arr, arr + n)) - k - 1;
    ll mx = *(std::max_element(arr, arr + n)) + 1;

	{
	    ll l = mn, r = mx;

		while (r - l > 1) {
			ll m = (l + r) >> 1;
			ll geq = 0;
			for (int i = 0; i < n; ++i) {
				if (arr[i] >= m) geq += (arr[i] - m + 1);
			}
			--geq;
			// dbg2(m, geq);
			if (geq < k) r = m;
			else l = m;
		}
		// use L
		dbg(l);
		mxel = l;
	}

	// ll mn = *(std::min_element(arr, arr + n));

	// if (mn >= mxel) {
	// 	ll sum = 0;
	// 	for (int i = 0; i < n; ++i) sum += arr[i];
	// 		dbg3(sum, mxel, sum % mxel);
	// 	if (sum % mxel) {
	// 		cout << "1\n";
	// 	} else {
	// 		cout << "0\n";
	// 	}
	// 	return 0;
	// }

	ll kk = k;
	for (int i = 0; i < n; ++i) {
		if (arr[i] > mxel) {
			k -= (arr[i] - mxel);
			arr[i] = mxel;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (arr[i] == mxel) {
			if (k) {--arr[i]; --k;}
			else break;
		}
	}

	ll mnel;
	{
		ll l = mn, r = mx;

		while (r - l > 1) {
			ll m = (l + r) >> 1;
		// for (int m = 0; m < mxel + 1; ++m) {
			ll leq = 0;
			for (int i = 0; i < n; ++i) {
				if (arr[i] <= m) leq += (m - arr[i] + 1);
			}
			--leq;
			// dbg2(m, leq);
			if (leq < kk) l = m;
			else r = m;
		}

		dbg(r);
		mnel = r;
	}

	for (int i = 0; i < n; ++i) {
		if (arr[i] < mnel) {
			kk -= (mnel - arr[i]);
			arr[i] = mnel;
		}
	}

	for (int i = 0; i < n; ++i) {
		if (arr[i] == mnel) {
			if (kk) {++arr[i]; --kk;}
			else break;
		}
	}


	cout << ((*(std::max_element(arr, arr + n))) - (*(std::min_element(arr, arr + n)))) << '\n';

    #ifdef LOCAL
    // cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}