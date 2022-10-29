#include <cstdio>
#include <iostream>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <functional>
#include <utility>
#include <map>
#include <vector>
#include <set>

#define maxn 100500

using namespace std;

const long long MD = 1000000007;
int n;
int a[maxn];
long long res = 0;
int div1[maxn], div2[maxn];
int sz, sz2;

inline void pb (int x, int i) {
	div1[sz++] = i;
	if (i * i != x)
		div2[sz2++] = x / i;
}

int make_calc (int x) {
	sz = sz2 = 0;
	pb (x, 1);
	for (int i = 2; i * i <= x; ++i)
		if (x % i == 0)
			pb (x, i);
	for (int i = sz2 - 1; i >= 0; --i)
		div1[sz++] = div2[i];
	return 0;
}

long long mypow (long long x, int pow) {
	long long res = 1, tmp = x;
	while (pow) {
		if (pow & 1) {
			res = (res * tmp) % MD;
			--pow;
		}
		pow >>= 1;
		tmp = (tmp * tmp) % MD;
	}
	return res;
}

int main () {
	//calc ();
	scanf ("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf ("%d", a + i);
	sort (a, a + n);
	int l, r, m;
	long long tmp, st, minus;
	for (int i = a[n - 1]; i >= 1; --i) {
		make_calc (i);
		int curl = 0;
		tmp = 1;
		st = 1;
		int prev = div1[0];
		for (int j = 0; j < sz - 1; ++j) {
			l = curl - 1, r = n;
			while (l < r - 1) {
				m = (l + r) / 2;
				if (a[m] >= div1[j + 1])
					r = m;
				else
					l = m;
			}
			tmp = (tmp * mypow (st, r - curl)) % MD;
			++st;
			curl = r;
		}
		minus = (mypow (st, n - curl) - mypow (st - 1, n - curl) + MD) % MD;
		res = (res + tmp * minus) % MD;
	}
	cout << res << endl;
	return 0;
}