#include <stdio.h>
#include <stdlib.h>
#include <vector>

int main() {
	int h, i, j;
	int t, n, k;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
	    scanf("%d", &n);
	    int max = 0;
	    while(n > 0) {
	        if(n%10 > max) {
	            max = n%10;
	        }
	        n /= 10;
	    }
	    printf("%d\n", max);
	}
}