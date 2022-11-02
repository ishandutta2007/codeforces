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
//#define DEBUG

std::mt19937 rnd(time(0));
using namespace std;

struct node {
	pair<int, int> x;
	int y, mx;
	node* left, * right;
	node(pair<int, int> x_) {
		x = x_;
		y = rnd();
		mx = x.second;
		left = nullptr;
		right = nullptr;
	}
};

int get_max(node* root) {
	return (root ? root->mx : -1e18);
}

void update(node* root) {
	if (!root)
		return;
	root->mx = max({ get_max(root->left), get_max(root->right), root->x.second });
}

node* merge(node * l, node * r) {
	if (!l)
		return r;
	if (!r)
		return l;
	update(l);
	update(r);
	if (l->y > r->y) {
		l->right = merge(l->right, r);
		update(l);
		return l;
	}
	else {
		r->left = merge(l, r->left);
		update(r);
		return r;
	}
}

pair<node*, node*> split(node * root, int x) {
	if (!root)
		return { nullptr, nullptr };
	update(root);
	if (root->x.first <= x) {
		auto [root1, root2] = split(root->right, x);
		root->right = root1;
		update(root);
		return { root, root2 };
	}
	else {
		auto [root1, root2] = split(root->left, x);
		root->left = root2;
		update(root);
		return { root1, root };
	}
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	vector<int> p(n + 1, 0);
	for (int i = 1; i <= n; ++i)
		p[i] = p[i - 1] + a[i];
	node* rootmen = new node({ 0, 0 });
	set<pair<int, int>> s;
	s.insert({ 0, 0 });
	vector<int> dp(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		if (a[i] > 0)
			dp[i] = dp[i - 1] + 1;
		else if (a[i] < 0)
			dp[i] = dp[i - 1] - 1;
		else
			dp[i] = dp[i - 1];
		auto [root1, root23] = split(rootmen, p[i] - 1);
		auto [root2, root3] = split(root23, p[i]);
		dp[i] = max(get_max(root1) + i, dp[i]);
		auto it = s.lb({ p[i], -1e18 });
		if (it != s.end() && it->first == p[i])
			dp[i] = max(dp[i], it->second);
		rootmen = merge(merge(root1, new node({ p[i], max(dp[i] - i, get_max(root2)) })), root3);
		if (it == s.end() || dp[i] > it->second) {
			if (it != s.end())
				s.erase(it);
			s.insert({ p[i], dp[i] });
		}
	}
	cout << dp[n] << "\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	cin >> t;
	while (t--)
		solve();
	return 0;
}