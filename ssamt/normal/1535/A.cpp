#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#include <vector>

int main() {
	int h, i, j, k;
	int t, n;
	int s[4];
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		for(i=0; i<4; i++) {
			scanf("%d", &s[i]);
		}
		if(std::max(s[0], s[1]) < std::min(s[2], s[3]) || std::min(s[0], s[1]) > std::max(s[2], s[3])) {
			printf("NO\n");
		} else {
			printf("YES\n");
		}
	}
}