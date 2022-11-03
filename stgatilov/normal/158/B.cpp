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

int n;
int cnt[8];

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	

	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		int v;
		scanf("%d", &v);
		cnt[v]++;
	}

	int ans = 0;

	ans += cnt[4];
	cnt[4] = 0;

	while (cnt[3]) {
		ans++;
		cnt[3]--;
		if (cnt[1]) cnt[1]--;
	}

	int pc = cnt[2] + (cnt[1] + 1) / 2;
	ans += (pc + 1) / 2;

	printf("%d\n", ans);

	return 0;
}