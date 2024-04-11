#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

int main() {
	int h, i, j, l;
	int t, n, m, k;
	char s[51];
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%s", s);
		int count = 0;
		for(i=0; s[i]; i++) {
			if(s[i] == 'B') {
				count++;
			} else {
				count--;
			}
		}
		if(count == 0) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}