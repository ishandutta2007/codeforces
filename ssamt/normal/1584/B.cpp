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
	int h, i, j, l;
	int t, n, m, k, q;
	int rev;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d %d", &n, &m);
		if(n%3 == 0 || m%3 == 0) {
			printf("%d\n", n*m/3);
		} else if(n%3 == m%3) {
			printf("%d\n", (n*m-4)/3+2);
		} else {
			printf("%d\n", (n*m-2)/3+1);
		}
	}
}