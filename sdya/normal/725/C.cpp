#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <stack>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 20;
int a[2][maxN];

vector < string > build(string s) {
	vector < int > cnt(26);
	for (int i = 0; i < s.size(); ++i) {
		++cnt[s[i] - 'A'];
	}

	int index;
	for (int i = 0; i < 26; ++i) {
		if (cnt[i] == 2) {
			index = i;
		}
	}

	vector < int > p;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == 'A' + index) {
			p.push_back(i);
		}
	}

	int l = p[0];
	int r = p[1];
	if (l + 1 == r) {
		return vector < string >();
	}

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 13; ++j) {
			a[i][j] = -1;
		}
	}

	int d = (r - l - 1);
	int x = 0;
	int y = (d <= 3 ? 1 : (d / 2));

	a[x][y] = index;
	vector < pair < int, int > > u, v;

	{
		int nx = x, ny = y - 1;
		int rem = d;
		while (rem > 0) {
			u.push_back(make_pair(nx, ny));
			--rem;
			if (nx == 0) {
				if (ny > 0) {
					--ny;
				} else {
					++nx;
				}
			} else {
				++ny;
			}
		}
	}
	{
		int nx = x, ny = y + 1;
		if (ny >= 13) {
			nx = 1;
			ny = 12;
		}

		int rem = 25 - d;
		while (rem > 0) {
			v.push_back(make_pair(nx, ny));
			--rem;
			if (nx == 0) {
				if (ny + 1 < 13) {
					++ny;
				} else {
					nx = 1;
					ny = 12;
				}
			} else {
				--ny;
			}
		}
	}

	for (int i = l + 1, j = 0; i < r; ++i, ++j) {
		a[u[j].first][u[j].second] = s[i] - 'A';
	}

	vector < pair < int, int > > v1, v2;
	for (int i = 0; i < v.size(); ++i) {
		if (i < l) {
			v1.push_back(v[i]);
		} else {
			v2.push_back(v[i]);
		}
	}
	reverse(v1.begin(), v1.end());
	reverse(v2.begin(), v2.end());

	for (int i = 0; i < l; ++i) {
		a[v1[i].first][v1[i].second] = s[i] - 'A';
	}
	for (int i = r + 1, j = 0; i < s.size(); ++i, ++j) {
		a[v2[j].first][v2[j].second] = s[i] - 'A';
	}

	vector < string > res;
	for (int i = 0; i < 2; ++i) {
		string cur;
		for (int j = 0; j < 13; ++j) {
			cur += 'A' + a[i][j];
		}
		res.push_back(cur);
	}
	return res;
}

pair < int, int > getPos(vector < string > &s, char c) {
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < s[i].size(); ++j) {
			if (s[i][j] == c) {
				return make_pair(i, j);
			}
		}
	}
	return make_pair(0, 0);
}

bool check(vector < string > res, string s) {
	if (res.size() == 0) {
		return true;
	}
	for (int i = 1; i < s.size(); ++i) {
		char u = s[i - 1], v = s[i];
		pair < int, int > x = getPos(res, u);
		pair < int, int > y = getPos(res, v);
		if (x == y) {
			return false;
		}
		if (abs(x.first - y.first) <= 1 && abs(x.second - y.second) <= 1) {
			continue;
		}
		return false;
	}
	return true;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	/*for (int i = 0; i < 27; ++i) {
		for (int j = i + 1; j < 27; ++j) {
			string s = "";
			char c = 'A';
			for (int k = 0; k < 27; ++k) {
				if (k == i || k == j) {
					s += 'Z';
				} else {
					s += c;
					++c;
				}
			}

			vector < string > res = build(s);
			if (res.size() == 0) {
				if (j > i + 1) {
					cerr << "FUCK" << endl;
				}
				continue;
			}
			if (!check(res, s)) {
				cerr << "FUCK" << endl;
			}
		}
	}*/

	string s;
	cin >> s;

	vector < string > res = build(s);
	if (res.size() == 0) {
		cout << "Impossible" << endl;
	} else {
		cout << res[0] << endl;
		cout << res[1] << endl;
	}

	//cout << check(res, s) << endl;
	


	return 0;
}