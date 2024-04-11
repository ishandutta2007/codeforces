#include <stdio.h>
//#include <limits.h>
//#include <time.h>
#include <algorithm>
//#include <vector>
//#include <cmath>
//#include <set>
//#include <queue>
//#include <string>
//#include <map>
//#include <functional>

using namespace std;

int main() {
	int h, i, j, l;
	int t, n, m, k, q;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		int a[n];
		int b[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		for(i=0; i<n; i++) {
			scanf("%d", &b[i]);
		}
		sort(a, a+n);
		sort(b, b+n);
		int check = 1;
		for(i=0; i<n; i++) {
			if(b[i] != a[i] && b[i] != a[i]+1) {
				check = 0;
				break;
			}
		}
		if(check) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	
}