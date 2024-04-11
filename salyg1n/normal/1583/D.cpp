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
//#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#pragma GCC optimize("O3")

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define print(a) for (auto& _ : a) cout << _ << " ";
#define input(a) for (auto& _ : a) cin >> _;
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define umap unordered_map
#define uset unordered_set
#define vll __int128

//#define int long long
//#define DEBUG

using namespace std;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> st1, st2;
	int x = 2;
	int k;
	do {
		cout << "? ";
		for (int i = 0; i < n - 1; ++i)
			cout << "1 ";
		cout << x << endl;
		cin >> k;
		st1.push_back(k);
		x++;
	} while (k != 0 && x <= n);
	if (x == n + 1 && k != 0)
		st1.push_back(0);
	x = 2;
	do {
		cout << "? ";
		for (int i = 0; i < n - 1; ++i)
			cout << x << " ";
		cout << 1 << endl;
		cin >> k;
		st2.push_back(k);
		x++;
	} while (k != 0 && x <= n);
	if (x == n + 1 && k != 0)
		st2.push_back(0);
	vector<int> p(n + 1);
	p[n] = st2.size();
	for (int i = 0; i < st2.size() - 1; ++i) {
		p[st2[i]] = st2.size() - i - 1;
	}
	for (int i = 0; i < st1.size() - 1; ++i) {
		p[st1[i]] = st2.size() + i + 1;
	}
	cout << "! ";
	for (int i = 1; i <= n; ++i)
		cout << p[i] << " ";
	cout << endl;
	return 0;
}