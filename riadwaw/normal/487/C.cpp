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


li binpow(li a, li b, li m) {
	if(!b)
		return 1;
	if(b % 2)
		return binpow(a, b - 1, m) * a % m;
	return binpow(a * a % m, b / 2, m);
}

void solve(int n) {

	if(n == 4) {
		cout << "YES\n1 3 2 4";
		return;
	}

	for(int j = 2; j * j <= n; ++j) {
		if(n % j == 0) {
			cout << "NO";
			return;
		}
	}
	set<int> s;
	cout << "YES\n";
	li have = 1;
	for(int i = 1; i < n; ++i) {
		li cur = i * binpow(have, n - 2, n) % n;
		s.insert(cur);
		have *= cur;
		have %= n;
		cout << cur << "\n";
	}
	assert(s.size() == n - 1);

	cout << n;
}
void solve() {
	int n;
	cin >> n;
	solve(n);

}