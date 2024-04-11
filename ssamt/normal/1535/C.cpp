#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#include <vector>

int main() {
	int h, i, j, k;
	int t, n;
	char s[200001];
	long long count;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%s", s);
		for(i=0; s[i]; i++);
		n = i;
		long long answer = 0;
		for(i=0; i<2; i++) {
			count = 0;
			for(j=0; j<n; j++) {
				if((j+i)%2 == s[j]-'0' || s[j] == '?') {
					count++;
				} else {
					answer += count*(count+1)/2;
					count = 0;
				}
			}
			answer += count*(count+1)/2;
		}
		count = 0;
		for(j=0; j<n; j++) {
			if(s[j] == '?') {
				count++;
			} else {
				answer -= count*(count+1)/2;
				count = 0;
			}
		}
		answer -= count*(count+1)/2;
		printf("%lld\n", answer);
	}
}