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

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	int q;
	scanf("%d", &q);

	for (int tt = 0; tt < q; tt++) {
		int n, r;
		scanf("%d%d", &n, &r);
		r--;

		int sum = 0;
		for (int i = 0; i < n-1; i++) {
			int x;
			scanf("%d", &x);
			x--;
			sum += x;
		}
		int ans = (n - sum % n + r) % n;

		printf("%d\n", ans+1);
	}

	return 0;
}