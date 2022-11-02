#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int h, i, j;
	int t, n;
	int in;
	cin >> t;
	for(h=0; h<t; h++) {
		cin >> n;
		char s[n+1];
		int found = 0;
		scanf("%s", s);
		for(i=0; i<n-1; i++) {
			if(s[i] != s[i+1]) {
				printf("%d %d\n", i+1, i+2);
				found = 1;
				break;
			}
		}
		if(!found) {
			printf("-1 -1\n");
		}
	}
}