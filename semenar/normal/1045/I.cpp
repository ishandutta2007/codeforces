/*
X
X
X
X
X
X
X
X
X
X
X
X
X
*/

#define _CRT_SECURE_NO_WARNINGS

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("sse4,tune=native")

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cstring>
#include <numeric>
#include <set>
#include <queue>
#include <deque>
#include <array>
#include <string>
#include <cmath>
#include <random>
#include <ctime>
#include <map>
#include <functional>
#include <bitset>
#include <complex>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define eb emplace_back
#define endl '\n'
#define mp make_pair

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using ld = long double;

const ll mod = 998244353;
const ld eps = 1e-8;

const ll inf = 1e9;
const ll INF = 1e18;

const ll P = 1e9 + 7;
const ll Q = 150001;

mt19937 rng(228);

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int N;
	cin >> N;

	vector<string> a(N);

	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	vector<int> conda(N);
	for (int i = 0; i < N; i++) {
		for (auto ch : a[i]) {
			conda[i] ^= (1 << (ch - 'a'));
		}
	}

	map<int, int> condacnt;
	for (auto el : conda) condacnt[el]++;

	ll res = 0;

	for (int i = 0; i < N; i++) {
		res += condacnt[conda[i]];
		for (int j = 0; j < 30; j++) if (condacnt.count(conda[i] ^ (1 << j))) res += condacnt[conda[i] ^ (1 << j)];
	}

	cout << (res - N) / 2 << endl;
}