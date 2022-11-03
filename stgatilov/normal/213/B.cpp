//#pragma comment(linker, "/STACK:20000000")
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

const int MOD = 1000000007;

inline void add(int &a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
}
inline void sub(int &a, int b) {
	a -= b;
	if (a < 0) a += MOD;
}
inline int mult(int a, int b) {
	return (int64(a) * b) % MOD;
}

const int SIZE = 128;
int comb[SIZE][SIZE];
int res[16][SIZE];

int SolveX(int len, vector<int> cnt) {
	memset(res, 0, sizeof(res));
	res[0][0] = 1;
	for (int i = 0; i<10; i++)
		for (int j = 0; j<=len; j++) if (res[i][j]) {
			for (int q = cnt[i]; j+q<=len; q++) {
//				printf("%d %d %d %d %d %d\n", i, j, i+1, j+q, comb[j+q][q], res[i][j]);
				add(res[i+1][j+q], mult(comb[j+q][q], res[i][j]));
			}
	}                       
	return res[10][len];	
}

int Solve(int len, vector<int> cnt) {
	int res = SolveX(len, cnt);
	vector<int> q = cnt;
	if (q[0]) q[0]--;
	sub(res, SolveX(len-1, q));
	return res;
}

int n;
vector<int> arr;

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	for (int i = 0; i<SIZE; i++) {
		comb[i][0] = comb[i][i] = 1;
		for (int j = 1; j<=i-1; j++) {
			comb[i][j] = comb[i-1][j-1];
			add(comb[i][j], comb[i-1][j]);
		}
	}

	scanf("%d", &n);
	arr.resize(10);
	for (int i = 0; i<10; i++)
		scanf("%d", &arr[i]);

	int ans = 0;
	for (int i = 1; i<=n; i++)
		add(ans, Solve(i, arr));
	printf("%d\n", ans);

	return 0;
}