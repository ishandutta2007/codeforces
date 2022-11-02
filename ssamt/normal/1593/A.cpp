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

using namespace std;

int main() {
	int h, i, j, l;
	int t, n, m, k;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		printf("%d ", max(a, max(b, c)+1)-a);
		printf("%d ", max(b, max(a, c)+1)-b);
		printf("%d ", max(c, max(a, b)+1)-c);
		printf("\n");
	}
}