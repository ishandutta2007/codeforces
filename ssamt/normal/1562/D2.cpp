#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <vector>

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int main() {
	int h, i, j, k;
	int t, n, q;
	int l, r;
	char s[300001];
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d %d", &n, &q);
		int count[n];
		scanf("%s", s);
		for(i=0; i<n; i++) {
			if(i%2 == 1) {
				s[i] = '+'+'-'-s[i];
			}
		}
		if(s[0] == '+') {
			count[0] = 1;
		} else {
			count[0] = -1;
		}
		for(i=1; i<n; i++) {
			if(s[i] == '+') {
				count[i] = count[i-1]+1;
			} else {
				count[i] = count[i-1]-1;
			}
		}
		std::vector<int> plus[2*n+1];
		std::vector<int> minus[2*n+1];
		if(s[0] == '+') {
			plus[n].push_back(0);
		} else {
			minus[n].push_back(0);
		}
		for(i=0; i<n-1; i++) {
			if(s[i+1] == '+') {
				plus[count[i]+n].push_back(i+1);
			} else {
				minus[count[i]+n].push_back(i+1);
			}
		}
		for(i=0; i<q; i++) {
			scanf("%d %d", &l, &r);
			int sum;
			if(l == 1) {
				sum = count[r-1];
			} else {
				sum = count[r-1]-count[l-2];
			}
			if((r-l+1)%2 == 0) {
				if(sum == 0) {
					printf("0\n");
				} else {
					printf("2\n");
					r--;
					if(s[r] == '+') {
						sum--;
					} else {
						sum++;
					}
					int find;
					if(l == 1) {
						find = (sum-1)/2;
					} else {
						find = count[l-2]+(sum-1)/2;
					}
					int idx = std::lower_bound(plus[find+n].begin(), plus[find+n].end(), l-1) - plus[find+n].begin();
					if(idx != plus[find+n].size() && l-1 <= plus[find+n][idx] && plus[find+n][idx] <= r-1) {
						printf("%d %d\n", plus[find+n][idx]+1, r+1);
					} else {
						if(l == 1) {
							find = (sum+1)/2;
						} else {
							find = count[l-2]+(sum+1)/2;
						}
						idx = std::lower_bound(minus[find+n].begin(), minus[find+n].end(), l-1) - minus[find+n].begin();
						if(idx != minus[find+n].size() && l-1 <= minus[find+n][idx] && minus[find+n][idx] <= r-1) {
							printf("%d %d\n", minus[find+n][idx]+1, r+1);
						}
					}
				}
			} else {
				printf("1\n");
				int find;
				if(l == 1) {
					find = (sum-1)/2;
				} else {
					find = count[l-2]+(sum-1)/2;
				}
				int idx = std::lower_bound(plus[find+n].begin(), plus[find+n].end(), l-1) - plus[find+n].begin();
				if(idx != plus[find+n].size() && l-1 <= plus[find+n][idx] && plus[find+n][idx] <= r-1) {
					printf("%d\n", plus[find+n][idx]+1);
				} else {
					if(l == 1) {
						find = (sum+1)/2;
					} else {
						find = count[l-2]+(sum+1)/2;
					}
					idx = std::lower_bound(minus[find+n].begin(), minus[find+n].end(), l-1) - minus[find+n].begin();
					if(idx != minus[find+n].size() && l-1 <= minus[find+n][idx] && minus[find+n][idx] <= r-1) {
						printf("%d\n", minus[find+n][idx]+1);
					}
				}
			}
		}
	}
}