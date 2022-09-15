//MIPT Ababahalamaha
#pragma comment (linker, "/STACK:128000000")
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <deque>
#include <cmath>
#include <ctime>
#include <stack>
#include <set>
#include <map>
#include <cassert>
#include <memory.h>
#include <sstream>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

typedef long long li;
typedef long long i64;
typedef long double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();


int main() {
#ifdef YA
	//assert(!s.empty());
	freopen("/Users/riad/ClionProjects/for-jhelper/input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	clock_t start = clock();
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen(FILENAME ".in", "r", stdin);
	//freopen(FILENAME ".out", "w", stdout); 
	cin.tie(0);
#endif
	cout.sync_with_stdio(0);
	cout.precision(10);
	cout << fixed;
	int t = 1;
	//cin >> t;
	while (t--) {
		//++timer;
		solve();
	}
#ifdef YA
	cerr<<"\n\n\n"<<(clock() - start) / 1.0 / CLOCKS_PER_SEC<<"\n\n\n";
#endif
	return 0;
}

vector<int> prefix_function (string s) {
	int n = (int) s.length();
	vector<int> pi (n);
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	return pi;
}

const int MOD = 1000000007;

int add(int v, int x) {
	v += x;
	if(v >= MOD) {
		v -= MOD;
	}
	return v;
}

void solve() {

	string s, t;
	cin >> s >> t;
	vi x = prefix_function(t + "#" + s);
	vector<int> mayStart(s.length() + 1, -1);
	for(int i = 0; i < x.size(); ++i) {
		if (x[i] == t.size()) {
			mayStart[i - t.size() - 1] = i - 2 * t.size();
		}
	}
	for(int i = 1; i < s.size(); ++i) {
		mayStart[i] = max(mayStart[i], mayStart[i - 1]);
	}

	vi dp(s.size() + 1);
	vi su(s.size() + 1);
	vi ss(s.size() + 1);
	dp[0] = 1;
	su[0] = 1;
	ss[0] = 1;

	for(int i = 0; i < s.size(); ++i) {
		if(mayStart[i] == -1) {
			dp[i + 1] = 0;
		}
		else
			dp[i + 1] = ss[mayStart[i]];
		su[i + 1] = add(dp[i + 1], su[i]);
		ss[i + 1] = add(su[i + 1], ss[i]);
	}




	cout << (MOD + su[s.size()] - 1) % MOD;

}