#include <stdio.h>
char inp[110];
int main() {
	int n;
	scanf("%d%s", &n, inp);
	int a = 0;
	for (int i=0; i<n; i++) {
		for (int j=1; i+4*j < n; j++) {
			for (int k=0; k<5; k++) {
				if (inp[i+j*k] != '*') break;
				if (k == 4) a = 1;
			}
		}
	}
	puts(a ? "yes" : "no");
	return 0;
}