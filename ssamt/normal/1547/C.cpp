#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <vector>

int main() {
	int h, i, j;
	int t, k, n, m;
	int a[100];
	int b[100];
	std::vector<int> order;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		fgetc(stdin);
		scanf("%d %d %d", &k, &n, &m);
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		for(i=0; i<m; i++) {
			scanf("%d", &b[i]);
		}
		order.clear();
		i = 0;
		j = 0;
		int check = 1;
		while(i < n || j < m) {
			if(j < m && b[j] == 0) {
				k++;
				j++;
				order.push_back(0);
			} else if(i < n && a[i] == 0) {
				k++;
				i++;
				order.push_back(0);
			} else if(i < n && a[i] <= k) {
				order.push_back(a[i]);
				i++;
			} else if(j < m && b[j] <= k) {
				order.push_back(b[j]);
				j++;
			} else {
				check = 0;
				break;
			}
		}
		if(check) {
			for(i=0; i<order.size(); i++) {
				printf("%d ", order[i]);
			}
			printf("\n");
		} else {
			printf("-1\n");
		}
	}
}