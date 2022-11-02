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
	    int a[n];
	    int answer[n+1];
	    int found = 0;
	    for(i=0; i<n; i++) {
	    	scanf("%d", &a[i]);
		}
		if(a[0] != 0) {
			answer[0] = n+1;
			for(i=1; i<=n; i++) {
				answer[i] = i;
			}
			found = 1;
		} else if(a[n-1] == 0) {
			for(i=0; i<=n; i++) {
				answer[i] = i+1;
			}
			found = 1;
		} else {
			for(i=0; i<n-1; i++) {
				if(a[i] == 0 && a[i+1] != 0) {
					for(j=0; j<=i; j++) {
						answer[j] = j+1;
					}
					answer[i+1] = n+1;
					for(j=i+2; j<=n; j++) {
						answer[j] = j;
					}
					found = 1;
					break;
				}
			}
		}
		if(found) {
			for(i=0; i<=n; i++) {
				printf("%d ", answer[i]);
			}
		} else {
			printf("-1");
		}
		printf("\n");
	}
}