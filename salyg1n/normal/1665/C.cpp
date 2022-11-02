//#define _GLIBCXX_DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
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
#include <time.h>
#include <chrono>
#include <fstream>
//#include <bits/stdc++.h>

typedef int_fast64_t ll;
typedef unsigned long long ull;
typedef long double ld;

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

#define int int_fast64_t
//#define int ll
#define DEBUG

//std::mt19937 rnd(time(0));
std::mt19937 rnd(time(0));
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1, 0);
	for (int i = 2; i <= n; ++i) {
		int p;
		cin >> p;
		a[p]++;
	}
	set<tuple<bool, int, int>> q;
	vector<int> cnt(n + 1, 0);
	set<int> s;
	a[0] = 1;
	for (int i = 0; i <= n; ++i) {
		if (a[i])
			q.insert({ 0, -a[i], i });
	}
	int k = 0;
	while (!get<0>(*q.begin()) || get<1>(*q.begin())) {
		k++;
		vector<int> tmp;
		for (auto i : s) {
			if (cnt[i] < a[i]) {
				q.erase({ 1,-(a[i] - cnt[i]), i });
				cnt[i]++;
				q.insert({ 1, -(a[i] - cnt[i]), i });
			}
			if (cnt[i] == a[i])
				tmp.push_back(i);
		}
		for (auto i : tmp)
			s.erase(i);
		int v = get<2>(*q.begin());
		q.erase(q.begin());
		cnt[v]++;
		q.insert({ 1, -(a[v] - cnt[v]), v });
		if (cnt[v] < a[v])
			s.insert(v);
	}
	cout << k << "\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}