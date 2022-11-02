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
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#pragma comment(linker, "/STACK:256000000")
#pragma warning(disable:4996)
using namespace std;
mt19937 rnd(time(NULL));
struct buk {
	int x;
	int y;
	int f;
	int s;
};
struct otv {
	int x1;
	int y1;
	int x2;
	int y2;
};
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int w = 0; w < t; w++) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>>a(n, vector<int>(m));
		vector<vector<pair<int, int>>>b(26);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				char tmp;
				cin >> tmp;
				if (tmp == '.') {
					a[i][j] = -1;
				}
				else {
					a[i][j] = tmp - 'a';
					b[a[i][j]].push_back({ i, j });
				}
			}
		}
		int x = 25;
		while (b[x].size() == 0 && x > 0) {
			x--;
		}
		if (x == 0 && b[x].size() == 0) {
			cout << "YES" << '\n';
			cout << 0 << '\n';
			continue;
		}
		vector<buk>c;
		int zzz = 0;
		for (int i = 0; i <= x; i++) {
			buk d;
			d.x = 0;
			d.y = 0;
			d.f = 0;
			d.s = 0;
			if (b[i].size() != 0) {
				int z1 = 0;
				int z2 = 0;
				for (int j = 1; j < (int)b[i].size(); j++) {
					if (b[i][j].first != b[i][j - 1].first) {
						z1 = 1;
					}
					if (b[i][j].second != b[i][j - 1].second) {
						z2 = 1;
					}
					if (z1 == 1 && z2 == 1) {
						zzz = 1;
						cout << "NO" << '\n';
						break;
					}
				}
				int mi = 10000;
				int ma = -1;
				if(zzz != 1){
					if (z1 == 0) {
						d.x = b[i][0].first;
						d.y = -1;
						for (int j = 0; j < (int)b[i].size(); j++) {
							mi = min(mi, b[i][j].second);
							ma = max(ma, b[i][j].second);
						}
						d.f = mi;
						d.s = ma;
					}
					else {
						d.x = -1;
						d.y = b[i][0].second;
						for (int j = 0; j < (int)b[i].size(); j++) {
							mi = min(mi, b[i][j].first);
							ma = max(ma, b[i][j].first);
						}
						d.f = mi;
						d.s = ma;
					}
				}
				else {
					break;
				}
			}
			c.push_back(d);
		}
		int fl = 0;
		if (zzz == 0) {
			vector<otv>ans(x + 1);
			for (int i = x; i > -1; i--) {
				int z = 0;
				if (b[i].size() == 0) {
					otv ot;
					ot.x1 = b[x][0].first;
					ot.x2 = b[x][0].first;
					ot.y1 = b[x][0].second;
					ot.y2 = b[x][0].second;
					ans[i] = ot;
				}
				else {
					if (c[i].x != -1) {
						for (int j = c[i].f; j <= c[i].s; j++) {
							if (a[c[i].x][j] == i) {
								a[c[i].x][j] = 100;
							}
							else {
								if (a[c[i].x][j] != 100) {
									z = 1;
									break;
								}
							}
						}
						if (z != 1) {
							otv ot;
							ot.x1 = c[i].x;
							ot.x2 = c[i].x;
							ot.y1 = c[i].f;
							ot.y2 = c[i].s;
							ans[i] = ot;
						}
					}
					else {
						if (c[i].y != -1) {
							for (int j = c[i].f; j <= c[i].s; j++) {
								if (a[j][c[i].y] == i) {
									a[j][c[i].y] = 100;
								}
								else {
									if (a[j][c[i].y] != 100) {
										z = 1;
										break;
									}
								}
							}
							if (z != 1) {
								otv ot;
								ot.y1 = c[i].y;
								ot.y2 = c[i].y;
								ot.x1 = c[i].f;
								ot.x2 = c[i].s;
								ans[i] = ot;
							}
						}
					}
					if (z == 1) {
						cout << "NO" << '\n';
						fl = 1;
						break;
					}
				}
			}
			if (fl == 0) {
				cout << "YES" << '\n';
				cout << x + 1 << '\n';
				for (int i = 0; i <= x; i++) {
					cout << ans[i].x1 + 1 << " " << ans[i].y1 + 1 << " " << ans[i].x2 + 1 << " " << ans[i].y2 + 1 << '\n';
				}
			}
		}
	}
	return 0;
}