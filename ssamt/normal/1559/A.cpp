#include <stdio.h>
#include <stdlib.h>
#include <vector>

int main() {
	int h, i, j;
	int t, n, k;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
	    scanf("%d", &n);
	    int a[n];
	    int answer = -1;
	    for(i=0; i<n; i++) {
	        scanf("%d", &a[i]);
	        answer &= a[i];
	    }
	    printf("%d\n", answer);
	}
}