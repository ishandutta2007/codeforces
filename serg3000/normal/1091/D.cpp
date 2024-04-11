#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <queue>
#include <deque>
#include <unordered_set>
#include <map>
#include<unordered_map>
#include <bitset>
#include <random>
#include <ctime>
using namespace std;
#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#pragma comment(linker, "/STACK:256000000")
#pragma warning(disable:4996)
const int mod = 998244353;
int binpow(int a, int n) {
	if (a >= mod) {
		a %= mod;
	}
	if (a < 0) {
		a += mod;
	}
	if (n == 0)
		return 1;
	if (n % 2 == 1) {
		int x = (binpow(a, n - 1) * a);
		if (x >= mod) {
			x %= mod;
		}
		if (x < 0) {
			x += mod;
		}
		return x ;
	}
	else {
		int b = (binpow(a, n / 2));
		if (b >= mod) {
			b %= mod;
		}
		if (b < 0) {
			b += mod;
		}
		b = b * b;
		if (b >= mod) {
			b %= mod;
		}
		if (b < 0) {
			b += mod;
		}
		return b;
	}
}
signed main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int ans = n;
	int z = n * (n - 2) * 2;
	for (int i = 1; i < n; i++) {
		ans += z;
		if (ans >= mod) {
			ans %= mod;
		}
		z = z % mod;
		if (ans < 0) {
			ans += mod;
		}
		int k = binpow((n - i - 1), mod - 2);
		if (k >= mod) {
			k %= mod;
		}
		z = z % mod;
		if (k < 0) {
			k += mod;
		}
		z = z * k;
		z = z % mod;
		if (z >= mod) {
			z %= mod;
		}
		if (z < 0) {
			z += mod;
		}

		int r = binpow(i + 1, mod - 2);
		if (r >= mod) {
			r %= mod;
		}
		if (r < 0) {
			r += mod;
		}
		z = z * r;
		if (z >= mod) {
			z %= mod;
		}
		z = z % mod;
		if (z < 0) {
			z += mod;
		}
		
		z *= (n - i - 2);
		if (z >= mod) {
			z %= mod;
		}
		z = z % mod;
		if (z < 0) {
			z += mod;
		}
		z *= (n - i);
		if (z >= mod) {
			z %= mod;
		}
		if (z < 0) {
			z += mod;
		}
		z = z % mod;
		z *= (i + 2);
		if (z >= mod) {
			z %= mod;
		}
		if (z < 0) {
			z += mod;
		}
		z = z % mod;
	}
	cout << ans;
	return 0;
}