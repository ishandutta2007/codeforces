#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <functional>
#include <utility>
#include <map>
#include <vector>
#include <set>

using namespace std;

const long long MD = 1000000007;
int m;
long long ans;
int siz[10][10];
long long cnt[10];
int lk[10];
int used[10];
long long fac[7] = {1, 1, 2, 6, 24, 120, 720};

long long mypow (long long x, long long pow) { 
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

int calc () {
	for (int i = 0; i < 7; ++i)
		fac[i] = mypow (fac[i], MD - 2);
	lk[4] = lk[7] = 1;
	siz [0][0] = 1;
	for (int i = 1; i <= 9; ++i) {
		siz[i][0] = 8 * siz[i - 1][0];
		for (int j = 0; j <= i; ++j) 
			siz[i][j] = 8 * siz[i - 1][j] + 2 * siz[i - 1][j - 1];
	}
	return 0;
}

int proc (int x) {
	int curd = 0, curpos = 0, st = 1;
	int fst = 1;
	while (st * 10 <= x) {
		st *= 10;
		++curpos;
	}
	int lcn = 0;
	//cerr << "curpos = " << curpos << endl;
	for (int i = curpos; i >= 0; --i) {
		curd = x / st;
		x %= st;
		//cerr << "curd = " << curd << endl;
		for (int j = 1 - fst; j < curd; ++j)
			for (int kk = 0; kk <= i; ++kk)
				cnt[lcn + lk[j] + kk] += (long long) (siz[i][kk]);
		lcn += lk[curd];
		st /= 10;
		fst = 1;
	}
	++cnt[lcn];
	return 0;
}

int gen (int pos, int rev, int re) {
	//cerr << "pos = " << pos << " rev = " << rev << endl;
	if (pos == 7) {
		long long tmp = 1;
		for (int i = 0; i < 10; ++i) {
			for (int jj = 1; jj <= used[i]; ++jj)
				tmp = (tmp * (cnt[i] - jj + 1)) % MD;
		}
		//printf ("tmp = %lld\n", tmp);
		//printf ("\n");
		ans = (ans + tmp * cnt[re]) % MD;
		return 0;
	}
	for (int j = 0; j <= rev; ++j) {
		++used[j];
		gen (pos + 1, rev - j, re);
		--used[j];
	}
	return 0;
}

int main () {
	cin >> m;
	calc ();
	/*for (int i = 0; i < 7; ++i)
		printf ("calc[%d] = %lld\n", i, fac[i]);*/
	if (m == 1000000000) {
		proc (m - 1);
		cnt[0]++;
	} else proc (m);
	--cnt[0];
	/*for (int i = 0; i < 9; ++i)
		cerr << "cnt[" << i << "] = " << cnt[i] << endl;*/
	for (int i = 1; i < 10; ++i)
		gen (1, i - 1, i);
	cout << ans << endl;
	return 0;
}