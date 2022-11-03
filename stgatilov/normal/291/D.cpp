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

const int SIZE = 10<<10;
const int TIME = 24;

int n, k;
int ans[TIME][SIZE];

int nowt;
int mem[SIZE], nmem[SIZE];
int pos[SIZE];

void EndTurn() {
	memcpy(mem, nmem, sizeof(mem));
	nowt++;
	memset(pos, -1, sizeof(pos));
	for (int i = 0; i<n; i++) pos[mem[i]] = i;
}

void Add(int where, int what) {
	int src = pos[what];
	assert(src >= 0);
	ans[nowt][where] = src;
	nmem[where] = mem[where] + mem[src];
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d%d", &n, &k);

	for (int i = 0; i<n; i++) nmem[i] = (i<n-1);
	EndTurn();
	nowt = 0;

	int done = 1;
	while (done+1 < n) {
		for (int i = 0; i<done; i++)
			Add(n-1-i, 0);
		int qq = min(n, 2*done);
		for (int i = done; i < qq; i++)
			Add(n-1-i, i-done);
		for (int i = qq; i<n; i++)
			Add(n-1-i, done);
		done = qq;
		EndTurn();
	}

	assert(nowt <= k);
	while (nowt < k) {
		for (int i = 0; i<n; i++) Add(i, 0);
		EndTurn();
	}

	for (int i = 0; i<k; i++) {
		for (int j = 0; j<n; j++) printf("%d ", ans[i][j] + 1);
		printf("\n");
	}

	return 0;
}