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
#define ll long long
#define x first
#define y second
#define res resize
#define pb push_back
#define rall(v) v.rbegin(), v.rend()
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define firn(i, n) for (int i = 1; i < (int)n; i++)
#define all(v) v.begin(), v.end()
mt19937 rnd(time(nullptr));
#define int long long
using namespace std;

signed main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int t;
	cin >> t;
	forn(w, t) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>>a(n, vector<int>(m));
		forn(i, n) {
			forn(j, m) {
				char x;
				cin >> x;
				if (x == '.') {
					a[i][j] = 0;
				}
				else {
					a[i][j] = 1;
				}
			}
		}
		forn(i, n / 3) {
			forn(j, m) {
				a[3 * i][j] = 1;
			}
		}
		int f = 0;
		forn(i, n) {
			
			if (i % 3 == 0) {
				f = 0;
				forn(j, m) {
					a[i][j] = 1;
				}
				continue;
			}
			if (i % 3 == 1) {
				if (i >= n / 3 * 3) {
					break;
				}

				forn(j, m) {
					if (a[i][j] == 1) {
						a[i + 1][j] = 1;
						f = 1;
						break;
					}
				}
			}
			if (i % 3 == 2 && f == 0) {
				forn(j, m) {
					if (a[i][j] == 1) {
						a[i - 1][j] = 1;
						f = 1;
						break;
					}
				}
				if (f == 0) {
					a[i][0] = 1;
					a[i - 1][0] = 1;
				}
			}
		}
		if (n % 3 == 0) {
			forn(j, m) {
				if (a[n - 2][j] == 1) {
					a[n - 1][j] = 1;
				}
				if (a[n - 1][j] == 1) {
					a[n - 2][j] = 1;
				}
			}
		}
		forn(i, n) {
			forn(j, m) {
				if (a[i][j] == 1) {
					cout << 'X';
				}
				else {
					cout << '.';
				}
			}
			cout << '\n';
		}
	}
	
	return 0;
}