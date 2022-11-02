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
		int x, y;
		scanf("%d %d", &x, &y);
		if(x > y) {
			printf("%d\n", x+y);
		} else if(x == y) {
			printf("%d\n", x);
		} else {
			printf("%d\n", ((y/x)*x+y)/2);
		}
	}
}