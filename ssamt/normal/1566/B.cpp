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
	int h, i, j, l;
	int t, n;
	char s[100001];
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%s", s);
		for(i=0; s[i]; i++);
		n = i;
		int count = 0;
		for(i=0; i<n; i++) {
			if(s[i] == '0') {
				if(i == n-1 || s[i+1] == '1') {
					count++;
				}
			}
		}
		if(count < 2) {
			printf("%d\n", count);
		} else {
			printf("2\n");
		}
	}
}