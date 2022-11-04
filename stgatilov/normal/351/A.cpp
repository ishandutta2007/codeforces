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

int n;
int arr[SIZE];

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d", &n);
	for (int i = 0; i<2*n; i++) {
		double q;
		scanf("%lf", &q);
		q *= 1000.0;
		int iq = int(q + 0.5);
		arr[i] = iq % 1000;
	}

	int sum = 0;
	for (int i = 0; i<2*n; i++)
		sum += arr[i];

	int nonint = 0;
	for (int i = 0; i<2*n; i++)
		nonint += (arr[i] != 0);

	Eo(sum);
	Eo(nonint);

	int ans = 1000000000;
	for (int j = max(nonint-n, 0); j <= min(nonint, n); j++) {
		int tdelta = 1000 * j - sum;
		if (ans > abs(tdelta))
			ans = abs(tdelta);
	}

	printf("%0.3lf\n", ans / 1000.0);

	return 0;
}