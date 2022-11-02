#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <vector>

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int main() {
	int h, i, j;
	int t, n;
	char s[11];
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%s", s);
		int answer = 10;
		for(i=0; i<2; i++) {
			int a[10];
			for(j=0; j<10; j++) {
				if(s[j] == '0') {
					a[j] = 0;
				} else if(s[j] == '1') {
					a[j] = 1;
				} else if(s[j] == '?') {
					a[j] = (i+j)%2;
				}
			}
			int score[2] = {};
			for(j=0; j<10; j++) {
				if(a[j] == 1) {
					score[j%2]++;
				}
				if(score[0]-score[1] > (10-j)/2) {
					answer = min(answer, j+1);
					break;
				}
				if(score[1]-score[0] > (9-j)/2) {
					answer = min(answer, j+1);
					break;
				}
			}
		}
		printf("%d\n", answer);
	}
}