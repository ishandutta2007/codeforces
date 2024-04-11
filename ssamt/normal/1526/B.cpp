#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int h, i, j, k;
	int t, n, m;
	int u, v;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		int answer;
		if(n < 111) {
			answer = (n%11 == 0);
		} else if(n < 111*11) {
			answer = (n-111*(n%11) >= 0);
		} else {
			answer = 1;
		}
		if(answer) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}