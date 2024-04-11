#include <bits/stdc++.h>

using namespace std;

int main() {
	int i, j, k, l;
	int t, n, m, q;
	scanf("%d", &t);
	for(int cl=0; cl<t; cl++) {
		scanf("%d", &n);
		for(i=(n-1)/2; i>=0; i--) {
			printf("%d ", i+1);
			if(i != 0 || n%2 == 0) {
				printf("%d ", i+n/2+1);
			}
		}
		printf("\n");
	}
}