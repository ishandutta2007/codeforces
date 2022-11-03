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

int64 Solve2(int64 left, int64 right, int dig) {
	right++;
	return ((right - dig) - left + 9) / 10;
}

int64 Solve(int64 num) {
	if (num < 10) return num;

	int64 pw = 1;
	while (pw <= num/10) pw *= 10;

	int first = num / pw;

	Eo(pw);
	Eo(num);
	Eo(first);

	int64 res = (first - 1) * pw / 10;
	res += Solve(pw - 1);
	res += Solve2(first * pw, num, first);

	Eo(num);
	Eo(res);
	return res;
}

int64 qleft, qright;

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%I64d%I64d", &qleft, &qright);

	int64 ans = Solve(qright) - Solve(qleft - 1);

	printf("%I64d\n", ans);

	return 0;
}