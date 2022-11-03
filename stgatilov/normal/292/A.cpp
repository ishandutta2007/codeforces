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

const int SIZE = 1024;

int n;
int tg[SIZE], ng[SIZE];

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d", &n);
	for (int i = 0; i<n; i++) scanf("%d%d", &tg[i], &ng[i]);

	int maxqs = 0;

	int qs = 0;
	for (int i = 0; i<n; i++) {
		int delta = (i ? tg[i] - tg[i-1] : 0);
		qs = max(qs - delta, 0);
		qs += ng[i];
		maxqs = max(maxqs, qs);
	}

	int ans = tg[n-1] + qs;

	printf("%d %d\n", ans, maxqs);

	return 0;
}