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

ll cnt[3][3];
const ll mod = 998244353;

const int MAXN = 2e5 + 10;

ll fact[MAXN];

ll power(ll a, ll n) {
	if (n == 0)
		return 1;
	if (n % 2 == 0) {
		ll tmp = power(a, n / 2);
		return tmp * tmp % mod;
	}
	return power(a, n - 1) * a % mod;
}

ll Div(ll a, ll b) {
	return a * power(b, mod - 2) % mod;
}

ll cnk(ll n, ll k) {
	return Div(fact[n], fact[k] * fact[n - k] % mod);
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	fact[0] = 1;
	for (int i = 1; i < MAXN; ++i) 
		fact[i] = (fact[i - 1] * i) % mod;
	
	int n;
	cin >> n;
	vector<pair<int, int>> a;
	for (int i = 0; i < n; ++i) {
		char c1, c2;
		cin >> c1 >> c2;
		a.push_back({ (c1 == 'W' ? 1 : (c1 == 'B' ? 2 : 0)), (c2 == 'W' ? 1 : (c2 == 'B' ? 2 : 0)) });
	}
	int cnt1 = 0, cnt2 = 0, cnt0 = 0;
	for (auto [c1, c2] : a) {
		if (c1 == 1)
			cnt1++;
		if (c1 == 2)
			cnt2++;
		if (c1 == 0)
			cnt0++;
		if (c2 == 1)
			cnt1++;
		if (c2 == 2)
			cnt2++;
		if (c2 == 0)
			cnt0++;
	}
	if (cnt1 > cnt2 + cnt0) {
		cout << "0\n";
		return 0;
	}
	if (cnt2 > cnt1 + cnt0) {
		cout << "0\n";
		return 0;
	}
	for (auto [c1, c2] : a) {
		cnt[c1][c2]++;
	}
	ll ans = 0;
	if (!cnt[2][1] && !cnt[2][0] && !cnt[0][1] && !cnt[2][2] && !cnt[1][1])
		ans++;
	if (!cnt[1][2] && !cnt[1][0] && !cnt[0][2] && !cnt[2][2] && !cnt[1][1])
		ans++;
	ll res = cnk(cnt0, (cnt0 + abs(cnt1-cnt2)) / 2);
	if (!cnt[1][1] && !cnt[2][2]) {
		res -= power(2, cnt[0][0]);
		res = (res % mod + mod) % mod;
	}
	cout << ans + res;
	return 0;
}