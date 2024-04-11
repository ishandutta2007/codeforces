#include <bits/stdc++.h>

using namespace std;

int main() {
	int i, j, k, l;
	int t, n, m, q;
	scanf("%d", &t);
	for(int cl=0; cl<t; cl++) {
		scanf("%d", &n);
		vector<int> a(n);
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		int sum = 0;
		for(i=0; i<n; i++) {
			sum += a[i];
		}
		if(sum%2 == 1) {
			printf("-1\n");
		} else {
			if(sum < 0) {
				for(i=0; i<n; i++) {
					a[i] = -a[i];
				}
				sum = -sum;
			}
			vector<int> answer;
			for(i=1; i<n; i++) {
				if(sum == 0) {
					break;
				}
				if(a[i] == 1 && (answer.empty() || answer.back() != i-1)) {
					answer.push_back(i);
					sum -= 2;
				}
			}
			if(sum == 0) {
				int idx = 0;
				printf("%d\n", n-answer.size());
				for(i=0; i<n; i++) {
					if(idx < answer.size() && answer[idx] == i+1) {
						printf("%d %d\n", i+1, i+2);
						idx++;
						i++;
					} else {
						printf("%d %d\n", i+1, i+1);
					}
				}
			} else {
				printf("-1\n");
			}
		}
	}
}