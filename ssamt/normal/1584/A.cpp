#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <queue>
#include <string>
#include <map>
#include <functional>

using namespace std;

int main() {
	int h, i, j, l;
	int t, n, m, k, q;
	int rev;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		long long u, v;
		scanf("%lld %lld", &u, &v);
		printf("%lld %lld\n", -u*u, v*v);
	}
}