//#define _GLIBCXX_DEBUG
#include <iostream>
#include <iomanip>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include <deque>
#include <string>
#include <cmath>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <fstream>
#include <cassert>
#include <random>
#include <cstring>
#include <climits>
//#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#pragma GCC optimize("O3")

#pragma GCC target("avx,avx2,sse3,ssse3,sse4.1,sse4.2,tune=native")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")


#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define print(a) for (auto& _ : a) cout << _ << " ";
#define input(a) for (auto& _ : a) cin >> _;
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define umap unordered_map
#define uset unordered_set
#define mset multiset
#define umset unordered_multiset
#define vll __int128

//#define x first
//#define y second

//#define int long long
//#define DEBUG

using namespace std;

struct Vector {
	ll x, y;
	Vector(ll x_ = 0, ll y_ = 0) {
		x = x_;
		y = y_;
	}
	ld len() {
		return sqrtl(x * x + y * y);
	}

	friend istream& operator>>(istream& c, Vector& v) {
		cin >> v.x >> v.y;
		return c;
	}

	friend ostream& operator<<(ostream& c, Vector v) {
		cout << v.x << " " << v.y;
		return c;
	}

	friend Vector operator+(const Vector& a, const Vector& b) {
		return Vector(a.x + b.x, a.y + b.y);
	}

	friend Vector operator-(const Vector& a, const Vector& b) {
		return Vector(a.x - b.x, a.y - b.y);
	}

	friend Vector operator* (const Vector& a, ll k) {
		return Vector(a.x * k, a.y * k);
	}

	friend ll operator*(Vector a, Vector b) {
		return a.x * b.x + a.y * b.y;
	}

	friend ll operator^(Vector a, Vector b) {
		return a.x * b.y - a.y * b.x;
	}

	friend void operator+=(Vector& a, Vector b) {
		a = a + b;
	}

	friend void operator-=(Vector& a, Vector b) {
		a = a - b;
	}

	friend bool operator==(Vector a, Vector b) {
		return a.x == b.x && a.y == b.y;
	}
};

ll triangle_square(Vector a, Vector b, Vector c) {
	if (a.x != b.x)
		return abs(b.x - a.x) * abs(c.y - a.y);
	else
		return abs(b.y - a.y) * abs(c.x - a.x);
}

void solve() {
	int w, h;
	cin >> w >> h;
	vector<ll> a, b, c, d;
	int k;
	cin >> k;
	a.resize(k);
	input(a);
	cin >> k;
	b.resize(k);
	input(b);
	cin >> k;
	c.resize(k);
	input(c);
	cin >> k;
	d.resize(k);
	input(d);
	ll ans = 0;
	for (int i = 0; i < b.size(); ++i) {
		ans = max(ans, triangle_square({ a[0], 0 }, { a.back(), 0 }, { b[i], h }));
	}
	for (int i = 0; i < c.size(); ++i) {
		ans = max(ans, triangle_square({ a[0], 0 }, { a.back(), 0 }, { 0, c[i] }));
	}
	for (int i = 0; i < d.size(); ++i) {
		ans = max(ans, triangle_square({ a[0], 0 }, { a.back(), 0 }, { w, d[i] }));
	}
	//---
	for (int i = 0; i < a.size(); ++i) {
		ans = max(ans, triangle_square({ b[0], h }, { b.back(), h }, { a[i], 0 }));
	}
	for (int i = 0; i < c.size(); ++i) {
		ans = max(ans, triangle_square({ b[0], h }, { b.back(), h }, { 0, c[i] }));
	}
	for (int i = 0; i < d.size(); ++i) {
		ans = max(ans, triangle_square({ b[0], h }, { b.back(), h }, { w, d[i] }));
	}
	//---
	for (int i = 0; i < a.size(); ++i) {
		ans = max(ans, triangle_square({ 0, c[0] }, { 0, c.back() }, { a[i], 0 }));
	}
	for (int i = 0; i < b.size(); ++i) {
		ans = max(ans, triangle_square({ 0, c[0] }, { 0, c.back() }, { b[i], h }));
	}
	for (int i = 0; i < d.size(); ++i) {
		ans = max(ans, triangle_square({ 0, c[0] }, { 0, c.back() }, { w, d[i] }));
	}
	//---
	for (int i = 0; i < a.size(); ++i) {
		ans = max(ans, triangle_square({ w, d[0] }, { w, d.back() }, { a[i], 0 }));
	}
	for (int i = 0; i < b.size(); ++i) {
		ans = max(ans, triangle_square({ w, d[0] }, { w, d.back() }, { b[i], h }));
	}
	for (int i = 0; i < c.size(); ++i) {
		ans = max(ans, triangle_square({ w, d[0] }, { w, d.back() }, { 0, c[i] }));
	}
	cout << ans << "\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}