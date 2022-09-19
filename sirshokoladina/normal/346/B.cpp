#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <cassert>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; --i)
#define bp push_back
#define mp make_pair
#define fs first
#define sc s econd
#define sqr(a) ((a) * (a))
#define all(a) a.begin(), a.end()

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;

const ld pi = 3.1415926535897932384626433832795l;

int e[110][30];

int p1[110][110][110], p2[110][110][110], p3[110][110][110], ans[110][110][110];
char c[110][110][110];

int main () {
#ifndef SUKPZDC
	//freopen(".in", "rt", stdin);
	//freopen(".out", "wt", stdout);
#else
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif
	string s1, s2, v;
	cin >> s1 >> s2 >> v;
	forn (i, v.size() + 1) {
		forn (j, 26) {
			ford (k, min(i + 2, (int)v.size() + 1)) {
				if (k == 0) {
					e[i][j] = k;
					break;
				} else {
					if (v[k - 1] != 'A' + j) {
						continue;
					}
					bool ok = 1;
					forn (l, k - 1) {
						if (v[k - 2 - l] != v[i - 1 - l]) {
							ok = 0;
							break;
						}
					}
					if (ok) {
						e[i][j] = k;
						break;
					}
				}
			}
		}
	}
//	forn (i, v.size() + 1) {
//		forn (j, 2) {
//			cout << i << ' ' << j << ' ' << e[i][j] << endl;
//		}
//	}
	memset(p1, -1, sizeof p1);
	memset(p2, -1, sizeof p2);
	memset(p3, -1, sizeof p3);
	memset(ans, 0, sizeof ans);
	forn (i, s1.size() + 1) {
		forn (j, s2.size() + 1) {
			forn (k, v.size()) {
				if (i < (int)s1.size() && j < (int)s2.size() && s1[i] == s2[j]) {
					if (ans[i + 1][j + 1][e[k][s1[i] - 'A']] < ans[i][j][k] + 1) {
						ans[i + 1][j + 1][e[k][s1[i] - 'A']] = ans[i][j][k] + 1;
						p1[i + 1][j + 1][e[k][s1[i] - 'A']] = i;
						p2[i + 1][j + 1][e[k][s1[i] - 'A']] = j;
						p3[i + 1][j + 1][e[k][s1[i] - 'A']] = k;
						c[i + 1][j + 1][e[k][s1[i] - 'A']] = s1[i];
					}
				}
				if (ans[i + 1][j][k] < ans[i][j][k]) {
					ans[i + 1][j][k] = ans[i][j][k];
					p1[i + 1][j][k] = i;
					p2[i + 1][j][k] = j;
					p3[i + 1][j][k] = k;
					c[i + 1][j][k] = '_';
				}
				if (ans[i][j + 1][k] < ans[i][j][k]) {
					ans[i][j + 1][k] = ans[i][j][k];
					p1[i][j + 1][k] = i;
					p2[i][j + 1][k] = j;
					p3[i][j + 1][k] = k;
					c[i][j + 1][k] = '_';
				}
			}
		}
	}
	string res = "";
	int k = 0;
	int mx = 0;
	forn (q, v.size()) {
		if (ans[s1.size()][s2.size()][q] > mx) {
			mx = ans[s1.size()][s2.size()][q];
			k = q;
		}
	}
	if (mx == 0) {
		puts("0");
		return 0;
	}
	int i = s1.size();
	int j = s2.size();
	while (i >= 0) {
		int i_ = p1[i][j][k];
		int j_ = p2[i][j][k];
		int k_ = p3[i][j][k];
		if (c[i][j][k] >= 'A' && c[i][j][k] <= 'Z') {
			res = c[i][j][k] + res;
		}
		i = i_;
		j = j_;
		k = k_;
	}
	puts(res.c_str());
	return 0;
}