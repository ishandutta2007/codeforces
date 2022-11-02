#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <iostream>
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
	int t, n, m, k;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d %d", &n, &m);
		int a, b, c;
		int arr[n] = {};
		for(i=0; i<m; i++) {
			scanf("%d %d %d", &a, &b, &c);
			arr[b-1] = 1;
		}
		int root;
		for(i=0; i<n; i++) {
			if(!arr[i]) {
				root = i;
			}
		}
		for(i=0; i<n; i++) {
			if(i != root) {
				printf("%d %d\n", i+1, root+1);
			}
		}
	}
}