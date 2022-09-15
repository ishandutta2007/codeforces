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


void solve() {


	cin >> n >> m;
	vector<string> s(n);
	for(int i = 0; i < n; ++i)
		cin >> s[i];


	unsigned ans = -1;


	for(int iter = 0; iter < 2; ++iter) {
		vector<vector<int>> pref(n + 1, vi(m + 1, 0));

		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				pref[i][j] = (s[i - 1][j - 1] == 'X') + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
				//cout << pref[i][j];
			}
			//cout << "\n";
		}

		pi first = pi(-1, -1);
		int w = 0;



		for (int i = 0; i < n && first.first == -1; ++i) {
			for(int j = 0; j < m; ++j) {
				if(s[i][j] == 'X') {
					first = mp(i, j);
					while(j < m && s[i][j] == 'X') {
						++j;
						++w;
					}
					break;
				}
			}
		}

		int h = 1;

		vector<pi> starts;
		starts.push_back(first);

		int cntR = 0, cntB = 0;

		int curX = first.first;
		int curY = first.second;
		while(true) {

			//cout << curX << ' '<< curY << ' ' << w << ' ' << h << "\n";

			int z = (correct(curX + h, curY) && s[curX + h][curY] == 'X') + 2 * (correct(curX, curY + w) && s[curX][curY + w] == 'X');
			//cout << z << endl;
			if (z == 3) {
				++h;
			}
			else if(z == 2) {
				++curY;
				starts.push_back(mp(curX, curY));
				++cntR;
			}
			else if(z == 1) {
				++curX;
				starts.push_back(mp(curX, curY));
				++cntB;
			}
			else
				break;
		}

		bool ok = true;

		for(pi z: starts) {
			int x = z.first;
			int y = z.second;
			int cnt = pref[x + h][y + w] - pref[x][y + w] - pref[x + h][y] + pref[x][y];
			if(cnt != w * h) {
				//cout << cnt << "\n";
				//cout << z.first << ' '<< z.second << "\n";
				ok = false;
			}
		}


		ok = ok && (pref[n][m] == w * h + cntR * h + cntB * w);

		if(ok) {
			ans = min((unsigned)w * h, ans);
		}
		//cout << "swaps" << "\n";


		vector<string> t(m, string(n, 'a'));
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				t[j][i] = s[i][j];
			}
		}
		swap(s,t);
		swap(n, m);

	}


	cout << (int)ans << "\n";
}