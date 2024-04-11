#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#define E(c) cerr<<#c
#define Eo(x) cerr<<#x<<" = "<<(x)<<endl

const int MOD = 1000000007;
inline void Add(int &a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
}
inline void Sub(int &a, int b) {
	a -= b;
	if (a < 0) a += MOD;
}

struct Bus {
	int st, end;
	inline Bus(int _s = 0, int _e = 0) : st(_s), end(_e) {}
	inline bool operator< (const Bus &x) const {
		return end < x.end;
	}
};

const int SIZE = 200<<10;

int n, m;
Bus arr[SIZE];

typedef map<int, int> mii;
mii cmap;


int res[SIZE], sum[SIZE];

inline int hgt(int x) { return ((x^(x+1))+1)>>1; }
void TreeAdd(int x, int t) {
	for (int i = x; i<SIZE; i += hgt(i))
		Add(sum[i], t);
}
int TreeSum(int x) {
	int res = 0;
	for (int i = x; i>=0; i -= hgt(i))
		Add(res, sum[i]);
	return res;
}


int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d%d", &n, &m);
	for (int i = 0; i<m; i++) {
		scanf("%d%d", &arr[i].st, &arr[i].end);
		cmap[arr[i].st] = 0;
		cmap[arr[i].end] = 0;
	}
	cmap[0] = 0;
	cmap[n] = 0;

	int k = 0;
	for (mii::iterator it = cmap.begin(); it != cmap.end(); it++)
		it->second = k++;

	for (int i = 0; i<m; i++) {
		arr[i].st = cmap[arr[i].st];
		arr[i].end = cmap[arr[i].end];
	}
	sort(arr, arr+m);

	res[0] = 1;
	TreeAdd(0, 1);
	for (int i = 0; i<m; i++) {
		int l = arr[i].st;
		int r = arr[i].end;
//		printf("%d %d\n", l, r);

		int tres = TreeSum(r-1);
		Sub(tres, TreeSum(l-1));

		Add(res[r], tres);
		TreeAdd(r, tres);
	}

	printf("%d\n", res[k-1]);
	
	return 0;
}