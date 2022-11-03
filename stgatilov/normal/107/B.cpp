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

int n, k, s;
int arr[1024];

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d%d%d", &k, &n, &s);
	s--;

	for (int i = 0; i<n; i++) scanf("%d", arr+i);
	arr[s]--;
	k--;

	int sum = 0;
	for (int i = 0; i<n; i++) sum += arr[i];

	if (sum < k) {
		printf("-1\n");
		return 0;
	}

	double bad = 0;
	if (k <= sum - arr[s]) {
		bad = 1.0;
		for (int j = 0; j<k; j++) {
			bad *= sum - arr[s] - j;
			bad /= sum - j;
		}
	}
	printf("%0.12lf\n", 1.0 - bad);

	return 0;
}