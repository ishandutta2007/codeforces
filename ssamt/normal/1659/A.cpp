#include <bits/stdc++.h>

using namespace std;

int main() {
	int i, j, k, l;
	int t, n, m, q;
	scanf("%d", &t);
	for(int cl=0; cl<t; cl++) {
		int r, b;
		scanf("%d %d %d", &n, &r, &b);
		for(i=0; i<=b; i++) {
			for(j=0; j<(r/(b+1)); j++) {
				printf("R");
			}
			if(i < r%(b+1)) {
				printf("R");
			}
			if(i != b) {
				printf("B");
			}
		}
		printf("\n");
	}
}