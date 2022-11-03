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

const int SIZE = 200<<10;

int n;
char str[2][SIZE];
int64 bsum[256][2];

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	

	scanf("%d", &n);
	scanf("%s", str[0]);
	scanf("%s", str[1]);

	int64 combs = 0;
	for (int i = 1; i<=n; i++) {
		int k = n + 1 - i;
		combs += int64(k) * k;
	}

	double sum = 0.0;
	for (int i = n-1; i>=0; i--) {
		for (int j = 0; j<2; j++)
			bsum[str[j][i]][j] += (n-1-i) + 1;
		for (int j = 0; j<2; j++)
			sum += bsum[str[j][i]][!j] * (i + 1);
		if (str[0][i] == str[1][i])
			sum -= int64(i + 1) * (n-1-i + 1);
	}

	double ans = sum / combs;
	printf("%0.15lf\n", ans);

	return 0;
}