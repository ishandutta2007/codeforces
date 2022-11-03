#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#define E(c) cerr<<#c
#define Eo(x) cerr<<#x<<" = "<<(x)<<endl

const int MOD = 1000000007;
const int DIGS = 11;
const int CNT = 6;

int pw10[32];
int comb[32][32];
int anti[32];

int n;
int group[32];
int res[DIGS+1][CNT+1][DIGS+1];


inline void add(int &a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
}
inline int mult(int a, int b) {
	return (int64(a)*b) % MOD;
}


bool lucky(int dig) { return dig == 4 || dig == 7; }

void SolveSimple(int ts, int cnt) {
	for (int i = 0; i<=cnt; i++) {
		int tres = comb[cnt][i];
		for (int j = 0; j<i; j++) tres *= 2;
		for (int j = 0; j<cnt-i; j++) tres *= 8;
		group[ts+i] += tres;
	}
}
                     
void Solve(int ts, int right) {
	if (right == 0)
		return;

	int pos = 0;
	while (pw10[pos] <= right) pos++;
	pos--;

	int ld = right / pw10[pos];
	for (int d = 0; d<ld; d++)
		SolveSimple(ts + lucky(d), pos);

	Solve(ts + lucky(ld), right % pw10[pos]);
}

int CalcVars(int from, int cnt) {
	if (cnt < 0 || cnt > from) return 0;

	int tres = 1;
	for (int i = 0; i<cnt; i++) {
		tres = mult(tres, from - i);
		tres = mult(tres, anti[i+1]);
	}
	return tres;
}

int main() {
#ifdef _CRT_SECURE_NO_DEPRECATE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);

	pw10[0] = 1;
	for (int i = 1; i<32; i++) pw10[i] = pw10[i-1] * 10;
	
	for (int i = 0; i<32; i++) {
		comb[i][0] = comb[i][i] = 1;
		for (int j = 1; j<i; j++)
			comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
	}

	for (int i = 1; i<=DIGS; i++) {
		for (int k = 0; ; k++) {
			int64 tt = int64(k) * MOD + 1;
			if (tt % i == 0) {
				anti[i] = tt / i;
				break;
			}
		}
		assert((int64(anti[i]) * i) % MOD == 1);
	}

	Solve(0, n + 1);
	group[0]--;

///	for (int i = 0; i<=DIGS; i++) printf("GRP %d %d\n", i, group[i]);

	res[0][0][0] = 1;
	for (int g = 0; g<DIGS; g++)
		for (int c = 0; c<=CNT; c++)
			for (int s = 0; s<=DIGS; s++) {
				int tres = res[g][c][s];
				if (!tres) continue;
///				printf("%d %d %d -> %d\n", g, c, s, tres);

                for (int a = 0; c+a <= CNT; a++) {
					int nc = c + a;
					int ns = s + a * g;
					if (ns > DIGS) continue;

					int vars = CalcVars(group[g], a);
					add(res[g+1][nc][ns], mult(vars, tres));
                }
			}

	int fact6 = 1*2*3*4*5*6;

	int ans = 0;
	for (int i = 0; i<=DIGS; i++) {
		int ourScore = i;
		int tres = group[i];
		for (int s = 0; s<i; s++) {
			int mlt = res[DIGS][CNT][s];
///			printf("MLT %d: %d\n", s, mlt);
			mlt = mult(mlt, fact6);
			add(ans, mult(mlt, tres));
		}
	}

	printf("%d\n", ans);

	return 0;
}