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
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int a1, a2, a3, a4;
	cin >> a1 >> a2 >> a3 >> a4;
	if (max(a1, a2) < min(a3, a4)) {
		cout << -1 << endl;
		return 0;
	}
	
	string x;
	bool haveX = false;
	for (int i = 0; i <= a1; ++i) {
		for (int j = i - 1; j <= i; ++j) {
			if (j < 0) {
				continue;
			}
			if (i + j == 0) {
				continue;
			}

			int c, d;
			if (i == j + 1) {
				c = j;
				d = j;
			} else {
				c = i;
				d = i - 1;
			}
			if (c != a3 || d != a4) {
				continue;
			}

			if (i > a1 || j > a2) {
				continue;
			}
			vector < int > p, q;
			for (int k = 0; k < i; ++k) {
				if (k == 0) {
					p.push_back(a1 - (i - 1));
				} else {
					p.push_back(1);
				}
			}
			for (int k = 0; k < j; ++k) {
				if (k + 1 == j) {
					q.push_back(a2 - (j - 1));
				} else {
					q.push_back(1);
				}
			}

			string current;
			int pi = 0, qi = 0;
			for (int k = 0; k < i + j; ++k) {
				if (k % 2 == 0) {
					for (int l = 0; l < p[pi]; ++l) {
						current += '4';
					}
					++pi;
				} else { 
					for (int l = 0; l < q[qi]; ++l) {
						current += '7';
					}
					++qi;
				}
			}
			if (current.size() != a1 + a2) {
				continue;
			}

			if (!haveX || current < x) {
				x = current;
				haveX = true;
			}
		}
	}

	string y;
	bool haveY = false;
	for (int i = 0; i <= a2; ++i) {
		for (int j = i - 1; j <= i; ++j) {
			if (j < 0) {
				continue;
			}
			if (i + j == 0) {
				continue;
			}

			int c, d;
			if (i == j + 1) {
				c = j;
				d = j;
			} else {
				c = i - 1;
				d = i;
			}
			if (c != a3 || d != a4) {
				continue;
			}

			if (i > a2 || j > a1) {
				continue;
			}
			vector < int > p, q;
			for (int k = 0; k < j; ++k) {
				if (k == 0) {
					p.push_back(a1 - (j - 1));
				} else {
					p.push_back(1);
				}
			}
			for (int k = 0; k < i; ++k) {
				if (k + 1 == i) {
					q.push_back(a2 - (i - 1));
				} else {
					q.push_back(1);
				}
			}

			string current;
			int pi = 0, qi = 0;
			for (int k = 0; k < i + j; ++k) {
				if (k % 2 == 1) {
					for (int l = 0; l < p[pi]; ++l) {
						current += '4';
					}
					++pi;
				} else { 
					for (int l = 0; l < q[qi]; ++l) {
						current += '7';
					}
					++qi;
				}
			}
			if (current.size() != a1 + a2) {
				continue;
			}

			if (!haveY || current < y) {
				y = current;
				haveY = true;
			}
		}
	}

	if (!haveX && !haveY) {
		cout << -1 << endl;
		return 0;
	}
	if (!haveX) {
		puts(y.c_str());
	} else if (!haveY) {
		puts(x.c_str());
	} else {
		puts(min(x, y).c_str());
	}

	return 0;
}