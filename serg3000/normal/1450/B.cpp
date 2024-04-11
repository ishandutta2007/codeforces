#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <queue>
#include <deque>
#include <unordered_set>
#include <map>
#include<unordered_map>
#include <bitset>
#include <random>
#include <ctime>
#include <fstream>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("vpt")
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define firn(i, n) for (int i = 1; i < (int)n; i++)
#define all(v) v.begin(), v.end()
mt19937 rnd(time(nullptr));
//#define int long long
using namespace std;
vector<vector<int>>g;
signed main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	forn(w, t) {
		int n, k;
		cin >> n >> k;
		vector<int>a(n), b(n);
		forn(i, n) {
			cin >> a[i] >> b[i];

		}
		
		vector<vector<int>>d(n, vector<int>(n));
		int f = 0;
		forn(i, n) {
			int c = 0;
			forn(j, n) {
				if (abs(a[i] - a[j]) + abs(b[i] - b[j]) <= k) {
					c++;
				}
			}
			if (c == n) {
				f = 1;
				cout << 1 << '\n';
				break;
			}
			
		}
		if (f == 0) {
			cout << -1 << '\n';
		}
	}
	//cout << -1;
	return 0;
}