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
		int n;
		cin >> n;
		vector<int>a(n);
		forn(i, n) {
			cin >> a[i];
			a[i]--;
		}
		vector<vector<int>>b(n);
		int l = 0;
		int r = n - 1;
		vector<int>ans(n);
		forn(i, n) {
			if (a[i] <= n - 1) {
				b[a[i]].push_back(i);
			}
		}
		vector<int>c = a;
		sort(all(c));
		int v = 0;
		forn(i, n) {
			if (c[i] != i) {
				v = 1;
			}
		}
		if (v == 0) {
			ans[n - 1] = 1;
		}
		forn(i, n) {
			if (b[i].size() == 0) {
				break;
			}
			if (a[l] != i && a[r] != i) {
				ans[i] = 1;
				break;
			}
			if (a[l] == i && a[r] == i) {
				ans[i] = 1;
				break;

			}
			int f = 0;
			forn(j, b[i].size()) {
				if (b[i][j] != l && b[i][j] != r) {
					ans[i] = 1;
					f = 1;
					break;
				}
			}
			if (a[l] == i) {
				l++;
				ans[i] = 1;
			}
			if (a[r] == i) {
				r--;
				ans[i] = 1;
			}
			if (f == 1) {
				break;
			}
		}

		reverse(all(ans));
		forn(i, n) {
			cout << ans[i];
		}
		cout << '\n';
	}
	return 0;
}