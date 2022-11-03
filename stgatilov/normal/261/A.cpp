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

const int SIZE = 100<<10;

int m, n;
int arr[SIZE];
int res[SIZE];
int k;

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	k = 1000000000;
	scanf("%d", &m);
	for (int j = 0; j<m; j++) {
		int tmp;
		scanf("%d", &tmp);
		k = min(k, tmp);
	}
	scanf("%d", &n);
	for (int i = 0; i<n; i++) scanf("%d", &arr[i]);

	sort(arr, arr+n);
	reverse(arr, arr+n);

	memset(res, -63, sizeof(res));
	res[0] = 0;
	for (int i = 0; i<n; i++) if (res[i] >= 0) {
		res[i+1] = max(res[i+1], res[i]);
		for (int d = 0; d<=2; d++) {
			int ni = i + k+d;
			if (ni > n) continue;
			int nres = res[i];
			for (int q = 0; q<d; q++) nres += arr[i+k+q];
			res[ni] = max(res[ni], nres);
		}
	}

	int sum = accumulate(arr, arr+n, 0);
	printf("%d\n", sum - res[n]);

	return 0;
}