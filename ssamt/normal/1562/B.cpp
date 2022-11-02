#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <vector>

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int main() {
	int h, i, j, k;
	int t, n;
	char s[51];
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		int answer = 0;
		int left;
		scanf("%d", &n);
		scanf("%s", s);
		for(i=0; i<n; i++) {
			if(s[i] == '1' || s[i] == '4' || s[i] == '6' || s[i] == '8' || s[i] == '9') {
				answer = 1;
				left = s[i]-'0';
				break;
			}
		}
		if(!answer) {
			for(i=1; i<n; i++) {
				if(s[i] == '2' || s[i] == '5') {
					answer = 2;
					left = (s[i-1]-'0')*10+s[i]-'0';
					break;
				} else if((s[0] == '2' && s[i] == '7') || (s[0] == '5' && s[i] == '7')) {
					answer = 2;
					left = (s[0]-'0')*10+s[i]-'0';
					break;
				}
			}
		}
		if(!answer) {
			int three=0, seven=0;
			for(i=0; i<n; i++) {
				if(s[i] == '3') {
					three++;
				} else if(s[i] == '7') {
					seven++;
				}
			}
			if(three > 1) {
				answer = 2;
				left = 33;
			} else if(seven > 1) {
				answer = 2;
				left = 77;
			}
		}
		printf("%d\n", answer);
		printf("%d\n", left);
	}
}