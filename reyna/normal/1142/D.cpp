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

const int N = (int) 12, mod = (int) 0;
long long dp[N][N][N], odp[N][N][N];
int nxt_st_sv[N][N][N][N], nxt_pos_sv[N][N][N][N], nxt_num_sv[N][N][N][N];
int main() {
	string s;
	cin >> s;
	int n = (int) s.size();
	long long res = 0;
	for (int cur = 0; cur <= 10; ++cur) {
		for (int st = 0; st <= 10; ++st)
			for (int num = 0; num <= 10; ++num) {
				for (int pos = 0; pos <= 10; ++pos) {
					int nxt_start = (st + num) % 11;
					int nxt_pos = nxt_start;
					for (int c = st; c != pos; c = (c + 1) % 11) {
						nxt_pos += c;
						nxt_pos %= 11;
					}
					nxt_pos = (nxt_pos + cur) % 11;
					int nxt_num = 0;
					for (int c = st, i = 0; i < num; ++i, c = (c + 1) % 11) {
						nxt_num = (nxt_num + c) % 11;	
					}
					nxt_st_sv[cur][st][num][pos] = nxt_start;
					nxt_pos_sv[cur][st][num][pos] = nxt_pos;
					nxt_num_sv[cur][st][num][pos] = nxt_num;
				}
			}
	}
	for (int j = 0; j < n; ++j) {
		memcpy(odp, dp, sizeof dp);
		memset(dp, 0, sizeof dp);
		int cur = s[j] - '0';
		if (cur != 0)
			dp[0][10][cur]++;
		for (int st = 0; st <= 10; ++st)
			for (int num = 0; num <= 10; ++num) {
				for (int pos = cur + 1; pos <= 10; ++pos) if (odp[st][num][pos]) {
					int nxt_start = nxt_st_sv[cur][st][num][pos];
					int nxt_pos = nxt_pos_sv[cur][st][num][pos];
					int nxt_num = nxt_num_sv[cur][st][num][pos];
					dp[nxt_start][nxt_num][nxt_pos] += odp[st][num][pos];
				}
			}
		for (int a = 0; a <= 10; ++a)
			for (int b = 0; b <= 10; ++b)
				for (int c = 0; c <= 10; ++c) if (dp[a][b][c]) {
					res += dp[a][b][c];
				}
					
	}
	cout << res << endl;
}