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
#define E(c) cerr<<#c
#define Eo(x) cerr<<#x<<" = "<<(x)<<endl

const int SIZE = 10<<20;

int64 n, l, t;
int64 arr[SIZE];
int64 ans;

int main() {
#ifdef _CRT_SECURE_NO_DEPRECATE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%I64d%I64d%I64d", &n, &l, &t);
	t *= 2;
	for (int i = 0; i<n; i++) scanf("%I64d", &arr[i]);

	int64 full = t / l;
	t -= full * l;
	int64 addall = full * (n-1);

	ans += n*addall;

	for (int i = 0; i<2*n; i++) arr[i+n] = arr[i] + l;
    for (int i = n-1; i>=0; i--) {
		int end = arr[i] + t;
		int idx = lower_bound(arr, arr+2*n, end) - arr;
		if (arr[idx] == end) idx++;
//		printf("[%I64d %I64d)\n", int64(i), int64(idx));
		ans += idx - i - 1;
    }

    printf("%0.15lf\n", ans * 0.25);


	return 0;
}