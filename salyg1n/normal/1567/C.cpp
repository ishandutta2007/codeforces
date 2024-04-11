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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		string n;
		cin >> n;
		ll ans = 0;
		for (ll mask = 0; mask < (1 << n.size()); ++mask) {
			if (in_mask(mask, 0) || in_mask(mask, 1))
				continue;
			ll now = 1;
			for (int i = n.size() - 1; i >= 0; --i) {
				if (i >= n.size() - 2) {
					if (in_mask(mask, i))
						now *= 10 - (n[i] - '0' + 1);
					else
						now *= n[i] - '0' + 1;
				}
				else {
					ll tmp = n[i] - '0';
					if (in_mask(mask, i + 2))
						tmp--;
					if (in_mask(mask, i))
						now *= 10 - (tmp + 1);
					else
						now *= tmp + 1;
				}
			}
			ans += now;
		}
		cout << ans - 2 << "\n";
	}
	return 0;
}