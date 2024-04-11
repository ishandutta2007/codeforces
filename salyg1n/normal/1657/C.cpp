//#define _GLIBCXX_DEBUG
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
#define umset unordered_multiset
#define vll __int128

//#define x first
//#define y second

#define int int_fast64_t
//#define int ll
//#define DEBUG

std::mt19937 rnd(time(0));
using namespace std;

const ll BASE = 29, MOD = 1e9 + 7;

void predpodchet(string s, vector<ll> & h, vector<ll> & pow, ll b, ll M) {
    int n = s.size();
    h.resize(n + 1, 0);
    pow.resize(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
        h[i] = (h[i - 1] * b + s[i - 1] - 'a' + 1) % M;
        pow[i] = pow[i - 1] * b % M;
    }
}

ll Hash(vector<ll> & h, vector<ll> & pow, ll b, ll M, ll l, ll r) {
    return (h[r] - (h[l - 1] * pow[r - l + 1] % M) + M) % M;
}

void solve() {
	int n;
	string s;
	cin >> n >> s;
    auto s1 = s;
    reverse(all(s1));
    vector<ll> h, hr, pow;
    predpodchet(s, h, pow, BASE, MOD);
    predpodchet(s1, hr, pow, BASE, MOD);
    int cnt = 0;
    int i;
    for (i = 0; i < n - 1;) {
        if (s[i] == '(') {
            i += 2;
            cnt++;
            continue;
        }
        bool flag = false;
        for (int j = i + 1; j < n; ++j) {
            if (Hash(h, pow, BASE, MOD, i + 1, j + 1) == Hash(hr, pow, BASE, MOD, n - (j + 1) + 1, n - (i + 1) + 1)) {
                i = j + 1;
                cnt++;
                flag = true;
                break;
            }
        }
        if (!flag)
            break;
    }
    cout << cnt << " " << n - i << "\n";
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