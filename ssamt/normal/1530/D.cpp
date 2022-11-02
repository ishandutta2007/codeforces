#include <stdio.h>
#include <stdlib.h>
#include <vector>

int main() {
	int h, i, j;
	int t, n;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		int a[n];
		int b[n];
		int found[n];
		std::vector<int> to[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
			a[i]--;
			to[a[i]].push_back(i);
			b[i] = -1;
			found[i] = 0;
		}
		for(i=0; i<n; i++) {
			if(to[i].size() > 0) {
				for(j=0; j<to[i].size(); j++) {
					if(to[to[i][j]].size() == 0) {
						b[to[i][j]] = i;
						break;
					}
				}
				if(j == to[i].size()) {
					b[to[i][0]] = i;
				}
				found[i] = 1;
			}
		}
		std::vector<int> left;
		for(i=0; i<n; i++) {
			if(b[i] == -1 && !found[i]) {
				left.push_back(i);
			}
		}
		if(left.size() == 1) {
			for(i=0; found[i] || i == left[0]; i++);
			b[left[0]] = i;
			found[i] = 1;
		} else if(left.size() > 1) {
			for(i=1; i<left.size(); i++) {
				b[left[i-1]] = left[i];
				found[left[i]] = 1;
			}
			b[left[left.size()-1]] = left[0];
			found[left[0]] = 1;
		}
		for(i=0, j=0; i<n && j<n;) {
			if(b[i] == -1 && !found[j]) {
				b[i] = j;
				found[j] = 1;
			}
			if(b[i] != -1) {
				i++;
			}
			if(found[j]) {
				j++;
			}
		}
		int answer = 0;
		for(i=0; i<n; i++) {
			if(a[i] == b[i]) {
				answer++;
			}
		}
		printf("%d\n", answer);
		for(i=0; i<n; i++) {
			printf("%d ", b[i]+1);
		}
		printf("\n");
	}
}