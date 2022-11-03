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

const int SIZE = 1<<20;


int n, k;
int len[2];
char str[2][1024];

int res[2][SIZE];

char buff[SIZE];
int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	gets(buff);
	sscanf(buff, "%d", &n);
	for (int u = 0; u<2; u++) {
		gets(str[u]);
		len[u] = strlen(str[u]);
	}
	k = len[0] * len[1];

	res[0][0] = res[1][0] = 0;
	for (int i = 0; i<k; i++) {
		char a = str[0][i % len[0]];
		char b = str[1][i % len[1]];

		int tres = 0;
		if (a != b) {
			if (a == 'R' && b == 'S' ||
				a == 'S' && b == 'P' ||
				a == 'P' && b == 'R')
				tres = -1;
			else
				tres = 1;
		}

		res[0][i+1] = res[0][i] + (tres > 0);
		res[1][i+1] = res[1][i] + (tres < 0);
	}

	int ans[2] = {0};
	for (int u = 0; u<2; u++)
		ans[u] = res[u][k] * (n / k) + res[u][n % k];

	printf("%d %d\n", ans[0], ans[1]);

	return 0;
}