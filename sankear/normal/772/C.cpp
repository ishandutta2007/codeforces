#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>
#include <set>
#include <bitset>
#include <map>
#include <deque>
#include <string>

#include <algorithm>
#include <numeric>

#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>

#define pb push_back
#define pbk pop_back
#define mp make_pair
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#define foreach(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
#define len(a) ((int) (a).size())

#ifdef CUTEBMAING
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

using namespace std;

typedef long long int64;
typedef long double ld;
typedef unsigned long long lint;

const int inf = (1 << 30) - 1;
const int64 linf = (1ll << 62) - 1;
const int N = 3e5 + 100;

int n, m;
set<int> a;

inline int gcd(int a, int b) {
	while (b > 0) {
		int y = a % b;
		a = b, b = y;
	}
	return a;
}

inline int euclid(int a, int b, int &x, int &y) {
	if (a == 0) {
		x = 0, y = 1;
		return b;
	}
	int x1, y1;
	int d = euclid(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

inline int solve(int a, int b, int c) {
	int d = gcd(gcd(a, b), c);
	assert(d != 0);
	a /= d, b /= d, c /= d;
	assert(c % gcd(a, b) == 0);
	int mult = c / gcd(a, b);
	int x, y; 
	assert(gcd(a, b) == euclid(a, b, x, y));
	return (1ll * x * mult) % m;
}

inline int inv(int a, int b) {
	if (b == 0) {
		return 0;
	}
	int result = solve(a, m, b);
	result = (result % m + m) % m;
	return result;
}

int main() {
#ifdef XCODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
    	int a; scanf("%d", &a);
    	::a.insert(a);
    }
    static vector<int> points[N];
    for (int i = 0; i < m; i++) {
    	if (!a.count(i)) {
    		points[gcd(i, m)].pb(i);
    	}
    }
    static int dp[N], parent[N];
    fill_n(parent, m + 1, -1);
    for (int i = 1; i <= m; i++) {
    	dp[i] = len(points[i]);
    	for (int j = 1; j * j <= i; j++) {
    		if (i % j == 0) {
    			if (i / j != i && dp[i] < dp[i / j] + len(points[i])) {
    				dp[i] = dp[i / j] + len(points[i]);
    				parent[i] = i / j;
    			}
    			if (i != j && dp[i] < dp[j] + len(points[i])) {
    				dp[i] = dp[j] + len(points[i]);
    				parent[i] = j;
    			}
    		}
    	}
    }
    int index = max_element(dp, dp + m + 1) - dp;
    vector<int> taken;
    while (parent[index] != -1) {
    	taken.pb(index);
    	index = parent[index];
    }
    taken.pb(index);
    reverse(all(taken));
    vector<int> prefix;
    for (int i : taken) {
    	for (int j : points[i]) {
    		prefix.pb(j);
    	}
    }
    vector<int> result;
    result.pb(prefix[0]);
    for (int i = 1; i < len(prefix); i++) {
    	result.pb(inv(prefix[i - 1], prefix[i]));
    	assert((1ll * prefix[i - 1] * result.back()) % m == prefix[i]);
    }
    cout << len(result) << endl;
    for (int i : result) {
    	printf("%d ", i);
    }
    puts("");
    return 0;
}