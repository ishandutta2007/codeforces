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
		scanf("%d", &n);
		printf("? 1 %d\n", n);
		fflush(stdout);
		long long all;
		scanf("%lld", &all);
		int left = 0;
		int right = n;
		while(left+1 < right) {
			int mid = (left+right)/2;
			printf("? 1 %d\n", mid+1);
			fflush(stdout);
			long long inv;
			scanf("%lld", &inv);
			if(all == inv) {
				right = mid;
			} else {
				left = mid;
			}
		}
		long long exclude;
		printf("? 1 %d\n", left+1);
		fflush(stdout);
		scanf("%lld", &exclude);
		int r = all-exclude+1;
		long long lsq = all-(long long)r*(r-1)/2;
		int l = (int)sqrt(2*lsq)+1;
		printf("! %d %d %d\n", right-r-l+2, right-r+2, right+1);
		fflush(stdout);
	}
}