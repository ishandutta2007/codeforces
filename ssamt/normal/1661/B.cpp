#include <bits/stdc++.h>

using namespace std;

int main() {
	int i, j, k, l;
	int t, n, m, q;
	scanf("%d", &n);
	for(i=0; i<n; i++) {
		int a;
		int answer = 16;
		scanf("%d", &a);
		for(j=0; j<16; j++) {
			int tar = (a+j)%32768;
			for(k=0; k<16; k++) {
				if(tar == 0) {
					break;
				}
				tar = (2*tar)%32768;
			}
			answer = min(answer, j+k);
		}
		printf("%d ", answer);
	}
	printf("\n");
}