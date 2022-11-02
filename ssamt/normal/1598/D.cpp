#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <string.h>
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
	int h, i, j, k;
	int t, n, m, q;
	char s[1000001];
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		long long ex = 0;
		int a[n][2];
		int count[n+1][2] = {};
		for(i=0; i<n; i++) {
			scanf("%d %d", &a[i][0], &a[i][1]);
			count[a[i][0]][0]++;
			count[a[i][1]][1]++;
		}
		for(i=0; i<n; i++) {
			ex += ((long long)count[a[i][0]][0]-1)*(count[a[i][1]][1]-1);
		}
		long long answer = (long long)n*(n-1)*(n-2)/6-ex;
		printf("%lld\n", answer);
	}
}