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
#ifdef HOME
	#define E(c) cerr<<#c
	#define Eo(x) cerr<<#x<<" = "<<(x)<<endl
	#define Ef(...) fprintf(stderr, __VA_ARGS__)
#else
	#define E(c) ((void)0)
	#define Eo(x) ((void)0)
	#define Ef(...) ((void)0)
#endif


int MOD = 12345;
inline void mdadd(int &a, int b) { a += b; if (a >= MOD) a -= MOD; }


typedef map<vector<int>, int> StateMap;
StateMap stMap;

int64 k;
int n, m, s;
bool has[32];
int p[32];
bool can[32][128];

vector<int> curr;
void DoStates(int u) {
	if (u == n) {
		int tt = stMap.size();
		stMap[curr] = tt;
		return;
	}
	for (int j = 0; j<p[u]; j++) {
		curr[u] = j;
		DoStates(u+1);
	}
}


struct Matrix {
	int a[128][128];
};
Matrix operator*(const Matrix &x, const Matrix &y) {
	Matrix res;
	for (int i = 0; i<s; i++)
		for (int j = 0; j<s; j++) {
			res.a[i][j] = 0;
			for (int u = 0; u<s; u++)
				res.a[i][j] = (res.a[i][j] + x.a[i][u] * y.a[u][j]) % MOD;
		}
	return res;
}


Matrix mdpow(Matrix a, int64 p) {
	Matrix r;
	for (int i = 0; i<s; i++) for (int j = 0; j<s; j++) r.a[i][j] = i==j;
	Matrix x = a;
	for (; p; p>>=1) {
		if (p & 1) r = r * x;
		x = x * x;
	}
	return r;
}

Matrix trans;
bool good[128];

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	n = 26;
	scanf("%I64d%d", &k, &m);
	for (int i = 0; i<m; i++) {
		char c;
		int a;
		scanf(" %c%d", &c, &a);
		int t = c - 'A';

		if (!has[t]) {
			has[t] = true;
			p[t] = 1;
		}
		for (int j = 0; j<128; j += a)
			can[t][j] = true;
		p[t] *= a;
	}

	int nn = 0;
	s = 1;
	for (int i = 0; i<n; i++)
		if (has[i]) {
            p[nn] = p[i];
			memcpy(can[nn], can[i], sizeof(can[0]));
			s *= p[nn];
		    nn++;
		}
	n = nn;

	if (n == 0) {
		printf("%d\n", k==0 ? 1 : 0);
		return 0;
	}

	curr.resize(n);
    DoStates(0);
    assert(stMap.size() == s);

	for (StateMap::iterator it = stMap.begin(); it != stMap.end(); it++) {
		const vector<int> &curr = it->first;

		good[it->second] = true;
		for (int i = 0; i<n; i++) if (!can[i][curr[i]])
			good[it->second] = false;
			
		for (int i = 0; i<n; i++) {
			vector<int> next = curr;
			next[i]++;
			if (next[i] == p[i]) next[i] = 0;
			mdadd(trans.a[it->second][stMap[next]], 1);
		}
	}

	Matrix pp = mdpow(trans, k);
	int ans = 0;
	for (int i = 0; i<s; i++) if (good[i])
		mdadd(ans, pp.a[0][i]);

	printf("%d\n", ans);

	return 0;
}