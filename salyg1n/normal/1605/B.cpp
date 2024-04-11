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
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define umap unordered_map
#define uset unordered_set
#define mset multiset
#define vll __int128
//#define x first
//#define y second

//#define int long long
//#define DEBUG

using namespace std;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		string s;
		cin >> s;
		string s1 = s;
		sort(all(s1));
		if (s == s1) {
			cout << "0\n";
			continue;
		}
		ll cnt0 = 0;
		for (auto c : s)
			if (c == '0')
				cnt0++;
		ll cnt1 = 0;
		for (int i = 0; i < cnt0; ++i)
			if (s[i] == '1')
				cnt1++;
		cout << 1 << "\n" << 2 * cnt1 << " ";
		for (int i = 0; i < n; ++i) {
			if (s[i] == '1' && i < cnt0)
				cout << i + 1 << " ";
			if (i >= cnt0 && s[i] == '0' && cnt1) {
				cout << i + 1 << " ";
				cnt1--;
			}
		}
		cout << "\n";
	}
	return 0;
}