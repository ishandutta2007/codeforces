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


int hp[2], attack[2], def[2];
void solve() {

	for(int i = 0; i < 2; ++i) {
		cin >> hp[i] >> attack[i] >> def[i];
	}

	int h, a, d;
	cin >> h >> a >> d;
	int mn = 1e9;
	for(int H = 0; H <= 10000; ++H) {
		for(int A = 0; A <= 200; ++A) {
			for(int D = 0; D <= 100; ++D) {
				int we = attack[0] + A - def[1];

				if(we <= 0)
					continue;
				int weneed = (hp[1] + we - 1) / we;

				int he = attack[1] - def[0] - D;

				if(he <= 0) {
					mn = min(mn, H * h + A * a +  D * d);
					continue;
				}
				int heneed = (hp[0] + H + he - 1)/ he;

				if(weneed < heneed) {
					mn = min(mn, H * h + A * a + D * d);
break;
				}

			}
		}
	}

	cout << mn;

}