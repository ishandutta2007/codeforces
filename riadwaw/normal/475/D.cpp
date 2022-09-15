/**
 * BE CAREFUL!! I have define int li sometimes
 */

//#define _GLIBCXX_DEBUG

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <cmath>
#include <ctime>
#include <stack>
#include <set>
#include <bitset>
#include <map>
#include <cassert>
#include <memory.h>
#include <limits>
#include <numeric>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

void solve();

void prec();


#define FILENAME "souvenir"

int main() {
	string s = FILENAME;
#ifdef DEBUG
	freopen("/Users/RiaD/Contests/Contests/input", "r", stdin);
	//freopen("/Users/RiaD/Contests/Contests/output", "w", stdout);
	//cout<<FILENAME<<endl;
	//assert (s != "change me please");
	clock_t start = clock();
#else
    //freopen(FILENAME ".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
#endif
	cout.sync_with_stdio(0);
	cout.precision(20);
	cout << fixed;
	//prec();
	int tests = 1;
	//cin >> tests;

	while (tests--) {
		solve();
	}
#ifdef DEBUG
	//cerr<<"\n\n"<<(clock() - start) / 1.0 / CLOCKS_PER_SEC<<"\n\n\n";
#endif
	return 0;
}

int n, m;
bool correct(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

int gcd(int a, int b) {
	while(b) {
		a %= b;
		swap(a, b);
	}
	return a;
}


void solve() {
	int n;

	cin >> n;

	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<pi> gcds;

	map<int, li> ans;

	for(int i = 0; i < n; ++i) {
		int val = a[i];
		gcds.push_back(mp(val, i));
		for(auto& x: gcds) {
			x.first = gcd(x.first, val);
		}
		for(int i = 1; i < gcds.size();) {
			if(gcds[i].first == gcds[i - 1].first) {
				gcds.erase(gcds.begin() + i);
			}
			else
				++i;
		}


		for(int j = 0; j < gcds.size(); ++j) {
			int posNext = (j + 1 == gcds.size())? (i + 1): (gcds[j + 1].second);
			//cout << "go" <<  gcds[j].first << ' ' << (posNext - gcds[j].second) << "\n";
			ans[gcds[j].first] += (posNext - gcds[j].second);
		}


	}

	int z;
	cin >> z;
	for(int i = 0; i < z; ++i) {
		int q;
		cin >> q;
		if(ans.count(q))
			cout << ans[q] << "\n";
		else
			cout << "0\n";
	}




}