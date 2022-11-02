#include <stdio.h>
#include <stdlib.h>
#include <vector>

int main() {
	int h, i, j;
	int t, n, k;
	char s[100];
	scanf("%d", &t);
	for(h=0; h<t; h++) {
	    scanf("%d", &n);
	    scanf("%s", s);
	    char answer[n];
	    for(i=0; s[i] == '?'; i++);
	    int cur;
	    if(s[i] == 'R') {
	    	cur = i%2;
		} else {
			cur = (i+1)%2;
		}
	    for(i=0; i<n; i++) {
	    	if(s[i] == '?') {
	    		if(cur == 0) {
	    			s[i] = 'R';
				} else {
					s[i] = 'B';
				}
				cur = 1-cur;
			} else {
				if(s[i] == 'R') {
					cur = 1;
				} else {
					cur = 0;
				}
			}
		}
		printf("%s\n", s);
	}
}