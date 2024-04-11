#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<vector>
#include<set>
#include<algorithm>
#include<iostream>
#include<ctime>
#include<iomanip>
#include<cassert>
#include<memory>
#include<string>
#include<string.h>
#include<math.h>

using namespace std;

typedef double ld;
typedef long long li;

const int N = (1 << 20);
const int MOD = 1e9 + 7;
const int i2 = (MOD + 1) / 2;

int n;
string s;

void read() {
	cin >> n >> s;
}

int mul(int a, int b) {
	return li(a) * b % MOD;
}

int add(int x, int y) {
	x += y;
	while (x >= MOD)
		x -= MOD;
	while (x < 0)
		x += MOD;
	return x;
}

void upd(int & x, int y) {
	x = add(x, y);
}

int popcount(int mask) {
	int res = 0;
	while (mask) {
		res++;
		mask &= mask - 1;
	}
	return res;
}

void f(int a[N]) {
	for (int i = 1; 2 * i <= N; i *= 2) {
		for (int j = 0; j < N; j += 2 * i) {
			for (int k = 0; k < i; ++k) {
				int v = a[j + k], u = a[j + i + k];
				a[j + k] = add(v, -u);
				a[j + i + k] = add(v, u);
			}
		}
	}
}

void ff(int a[N]) {
	for (int i = N / 2; i >= 1; i /= 2) {
		for (int j = 0; j < N; j += 2 * i) {
			for (int k = 0; k < i; ++k) {
				int v = a[j + k], u = a[j + i + k];
				a[j + k] = mul(add(v, u), i2);
				a[j + i + k] = mul(add(u, -v), i2);
			}
		}
	}
}

int a[N];

void solve() {
	for (int i = 0; i < s.size(); ++i)
		a[i] = s[i] == '1';

	f(a);

	for (int i = 0; i < N; ++i)
		a[i] = li(a[i]) * a[i] % MOD;

	ff(a);

	int ans = 0;
	for (int mask = 0; mask < N; ++mask) {
		int d = n - popcount(mask);
		ans = (ans + (1LL << d) * a[mask]) % MOD;
	}
	ans = ans * li(3) % MOD;
	cout << ans << endl;
}

int main() {

	srand(time(NULL));

	read();
	solve();

	return 0;
}