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
//#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#pragma GCC optimize("O3")

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define print(a) for (auto& i : a) cout << i << " ";
#define input(a) for (auto& i : a) cin >> i;

//#define _GLIBCXX_DEBUG
//#define DEBUG

using namespace std;

ll lg(ll a) {
	ll res = 0;
	while (a) {
		a /= 10;
		res++;
	}
	return res;
}

bool in_mask(ll mask, ll i) {
	return mask & (1 << i);
}

ll power(ll a, ll n) {
	ll res = 1;
	while (n--)
		res *= a;
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		ll s, n;
		cin >> s >> n;
		vector<ll> a(10);
		int i = 0, cnt = 0;
		while (s) {
			a[i] = s % 10;
			cnt += a[i];
			s /= 10;
			i++;
		}
		while (cnt < n) {
			i = 1;
			while (!a[i])
				i++;
			a[i]--;
			a[i - 1] += 10;
			cnt += 9;
		}
		multiset<ll> st;
		for (i = 0; i < 10; ++i) {
			while (a[i]--) {
				st.insert(power(10, i));
			}
		}
		while (st.size() > n) {
			ll A = *st.begin();
			st.erase(st.begin());
			ll B = *st.begin();
			st.erase(st.begin());
			st.insert(A + B);
		}
		for (auto j : st)
			cout << j << " ";
		cout << "\n";
	}
	return 0;
}