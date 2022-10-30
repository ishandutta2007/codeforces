#include <bits/stdc++.h>

using namespace std;

int main() {
	int i, j, k, l;
	int t, n, m, q;
	scanf("%d", &t);
	for(int cl=0; cl<t; cl++) {
		scanf("%d %d", &n, &k);
		vector<int> s(k);
		for(i=0; i<k; i++) {
			scanf("%d", &s[i]);
		}
		if(k == 1) {
			printf("Yes\n");
		} else {
			int check = 1;
			for(i=0; i<k-2; i++) {
				if(s[i+2]-s[i+1] < s[i+1]-s[i]) {
					check = 0;
				}
			}
			if(!check) {
				printf("No\n");
			} else {
				if(s[0] > ((long long)s[1]-s[0])*(n-k+1)) {
					printf("No\n");
				} else {
					printf("Yes\n");
				}
			}
		}
	}
}