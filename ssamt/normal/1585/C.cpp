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
	int h, i, j;
	int t, n, m, k, q;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d %d", &n, &k);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		int neg = 0;
		for(i=0; i<n; i++) {
			if(a[i] < 0) {
				neg++;
			}
		}
		sort(a, a+n);
		long long answer = 0;
		for(i=0; i<neg; i+=k) {
			answer += 2*abs(a[i]);
		}
		for(i=n-1; i>=neg; i-=k) {
			answer += 2*abs(a[i]);
		}
		answer -= max(abs(a[0]), abs(a[n-1]));
		printf("%lld\n", answer);
	}
}