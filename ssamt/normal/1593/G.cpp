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
		scanf("%s", s);
		for(i=0; s[i]; i++);
		int n = i;
		int sum[n+1][2];
		sum[0][0] = sum[0][1] = 0;
		for(i=1; i<=n; i++) {
			sum[i][0] = sum[i-1][0];
			sum[i][1] = sum[i-1][1];
			if(s[i-1] == '(' || s[i-1] == ')') {
				sum[i][(i-1)%2]++;
			}
		}
		scanf("%d", &q);
		for(i=0; i<q; i++) {
			int l, r;
			scanf("%d %d", &l, &r);
			printf("%d\n", abs((sum[r][1]-sum[l-1][1])-(sum[r][0]-sum[l-1][0])));
		}
	}
}