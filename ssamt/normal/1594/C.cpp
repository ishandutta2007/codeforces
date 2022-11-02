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

using namespace std;

int main() {
	int h, i, j, l;
	int t, n, m, k;
	long long mod = 1000000007;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		char c;
		scanf("%d %c", &n, &c);
		char s[n+1];
		scanf("%s", s);
		bool all = true;
		for(i=0; i<n; i++) {
			if(s[i] != c) {
				all = false;
			}
		}
		if(all) {
			printf("0\n");
		} else {
			int any = 0;
			for(i=n/2; i<n; i++) {
				if(s[i] == c) {
					any = i;
				}
			}
			if(any) {
				printf("1\n%d\n", any+1);
			} else {
				printf("2\n%d %d\n", n-1, n);
			}
		}
	}
}