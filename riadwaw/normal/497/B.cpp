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
	cin.tie(0);
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
	int n;
	cin >> n;

	vi a(n);

	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		--a[i];
	}

	vi cntPrefix[2];
	cntPrefix[0].resize(n + 1);
	cntPrefix[1].resize(n + 1);


	vi whereNth[2];
	whereNth[0].resize(n + 2, 1000000);
	whereNth[1].resize(n + 2, 1000000);

	for(int i = 0; i < n; ++i) {
		cntPrefix[0][i + 1] = cntPrefix[0][i];
		cntPrefix[1][i + 1] = cntPrefix[1][i];
		cntPrefix[a[i]][i + 1] += 1;
		whereNth[a[i]][cntPrefix[a[i]][i + 1]] = i;
	}

	vector<pi> ans;

	for(int t = 1; t <= n; ++t) {
		int win[2] = {0, 0};
		int have[2] = {0, 0};
		while (true) {
			int ok[2];
			for(int i = 0; i < 2; ++i) {
				ok[i] = whereNth[i][min(have[i] + t, n + 1)];
			}
			if(ok[0] == 1000000 && ok[1] == 1000000) {
				break;
			}

			int winner = 0;
			if(ok[0] < ok[1]) {
				winner = 0;
			}
			else {
				winner = 1;

			}
			win[winner]++;
			int nextFirst = ok[winner];
			++nextFirst;


			for(int i = 0; i < 2; ++i)
				have[i] = cntPrefix[i][nextFirst];


			if (nextFirst == n) {
				if(win[winner] > win[!winner]) {
					ans.push_back(mp(win[winner], t));
				}
				break;
			}


		}

	}

	sort(all(ans));


	cout << ans.size() << "\n";
	for(int i = 0; i < ans.size(); ++i) {
		cout << ans[i].first << ' ' << ans[i].second << "\n";
	}

}