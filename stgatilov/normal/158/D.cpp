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
int arr[32768];
int sum[32768];

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d", &n);
	for (int i = 0; i<n; i++) scanf("%d", &arr[i]);

	int ans = -1000000000;
	for (int v = 3; v<=n; v++) {
		if (n % v) continue;
		int d = n / v;
		memset(sum, 0, sizeof(sum));
		for (int i = 0; i<n; i++) sum[i % d] += arr[i];

		for (int i = 0; i<d; i++) if (ans < sum[i])
			ans = sum[i];
	}

	printf("%d\n", ans);

	return 0;
}