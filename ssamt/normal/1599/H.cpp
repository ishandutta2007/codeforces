#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k;
	int t, n, m, q;
	int size = 1e9;
	int start = 0;
	int end = size;
	int sw, se, nw;
	printf("? 1 1\n");
	fflush(stdout);
	scanf("%d", &sw);
	while(start+1 < end) {
		int mid = (start+end)/2;
		printf("? %d 1\n", mid+1);
		fflush(stdout);
		int dist;
		scanf("%d", &dist);
		if(sw-dist == mid) {
			start = mid;
		} else {
			end = mid;
		}
	}
	printf("? %d 1\n", size);
	fflush(stdout);
	scanf("%d", &se);
	printf("? 1 %d\n", size);
	fflush(stdout);
	scanf("%d", &nw);
	printf("! %d %d %d %d\n", start+1, sw-start+1, size+sw-start-se, size+start-nw);
}