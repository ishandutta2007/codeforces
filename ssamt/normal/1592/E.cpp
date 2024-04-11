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
	scanf("%d", &n);
	int a[n];
	for(i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	vector<vector<int>> inter(1<<19, vector<int>{-1, -1});
	int answer = 0;
	for(i=0; i<20; i++) {
		for(j=0; j<inter.size(); j++) {
			inter[j][0] = -1;
			inter[j][1] = -1;
		}
		for(j=0; j<n; j++) {
			for(; j<n && !(a[j]&(1<<i)); j++);
			int l = j;
			for(; j<n && a[j]&(1<<i); j++);
			int r = j;
			int sum = 0;
			inter[0][l%2] = l;
			for(k=l; k<r; k++) {
				sum ^= a[k]>>(i+1);
				if(inter[sum][(k+1)%2] < l) {
					inter[sum][(k+1)%2] = k+1;
				} else {
					answer = max(answer, k+1-inter[sum][(k+1)%2]);
				}
			}
		}
	}
	printf("%d\n", answer);
}