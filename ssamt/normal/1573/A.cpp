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
	int h, i, j;
	int t, n;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		char a[n+1];
		scanf("%s", a);
		int answer = 0;
		for(i=0; i<n; i++) {
			answer += a[i]-'0';
			if(a[i] != '0' && i != n-1) {
				answer++;
			}
		}
		printf("%d\n", answer);
	}
}