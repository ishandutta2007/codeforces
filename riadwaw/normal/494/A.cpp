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


void solve() {

	string s;
	cin >> s;
	map<char, int> cnt;
	for(char c: s) {
		cnt[c] ++;
	}

	int need = cnt['('] - cnt[')'];
	if(need < cnt['#']) {
		cout << -1;
		return;
	}
	int has = 0;
	int bal = 0;
	for(char c: s) {
		if(c == '(') {
			bal++;
		}
		else if(c == ')') {
			bal--;
		}
		else {
			++has;
			if(has == cnt['#']) {
				bal -= need - cnt['#'] + 1;
			}
			else
				bal--;
		}
		if(bal < 0) {
			cout << -1;
			return;
		}

	}

	for(int i = 1; i < cnt['#']; ++i) {
		cout << 1 << '\n';
	}
	cout << need - cnt['#'] + 1;

}