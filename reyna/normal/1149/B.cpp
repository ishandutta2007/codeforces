// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> inline bool smin(T &a, const T &b)   { return a > b ? a = b : a;    }
template<typename T> inline bool smax(T &a, const T &b)   { return a < b ? a = b : a;    }

typedef long long LL;

const int N = (int) 1e5 + 5, mod = (int) 0;
int best[255][255][255], nxt[N][26];
int a[3][N], sz[3];
int main() {
	ios_base::sync_with_stdio(0);
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	for (int j = 0; j < 26; ++j) nxt[n][j] = nxt[n + 1][j] = n + 1;
	for (int j = n - 1; j >= 0; --j) {
		for (int c = 0; c < 26; ++c) {
			if (s[j] - 'a' == c) {
				nxt[j][c] = j;
			} else {
				nxt[j][c] = nxt[j + 1][c];
			}
		}
	}
	for (int i = 0; i < 255; ++i)
		for (int j = 0; j < 255; ++j)
			for (int k = 0; k < 255; ++k)
				best[i][j][k] = n + 1;
	best[0][0][0] = 0;
	while (q--) {
		char ch;
		cin >> ch;
		int rel;
		cin >> rel;
		--rel;
		if (ch == '+') {
			cin >> ch;
			a[rel][sz[rel]++] = ch - 'a';
			int stx = 0, edx = sz[0];
			int sty = 0, edy = sz[1];
			int stz = 0, edz = sz[2];
			if (rel == 0) {
				stx = sz[rel];
				edx = sz[rel];
			} else if (rel == 1) {
				edy = sz[rel];
				sty = sz[rel];
			} else {
				edz = sz[rel];
				stz = sz[rel];
			}
			for (int x = stx; x <= edx; ++x)
				for (int y = sty; y <= edy; ++y)
					for (int z = stz; z <= edz; ++z) {
						best[x][y][z] = n + 1;
						if (x > 0) {
							int pos = best[x - 1][y][z];
							int c = a[0][x - 1];
							int go = nxt[pos][c] + 1;
							go = min(go, n + 1);
							best[x][y][z] = min(best[x][y][z], go);
						}
						if (y > 0) {
							int pos = best[x][y - 1][z];
							int c = a[1][y - 1];
							int go = nxt[pos][c] + 1;
							go = min(go, n + 1);
							best[x][y][z] = min(best[x][y][z], go);
						}
						if (z > 0) {
							int pos = best[x][y][z - 1];
							int c = a[2][z - 1];
							int go = nxt[pos][c] + 1;
							go = min(go, n + 1);
							best[x][y][z] = min(best[x][y][z], go);
						}
						
					}
			
		} else {
			--sz[rel];	
		}
		cout << (best[sz[0]][sz[1]][sz[2]] <= n ? "YES\n" : "NO\n");
	}
	
}