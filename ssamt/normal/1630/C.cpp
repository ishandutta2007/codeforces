#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k;
	int t, n, m, q;
	int in;
	scanf("%d", &n);
	int a[n];
	for(i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	int min_idx[n+1];
	int max_idx[n+1];
	for(i=0; i<=n; i++) {
		min_idx[i] = n;
		max_idx[i] = -1;
	}
	for(i=0; i<n; i++) {
		min_idx[a[i]] = min(min_idx[a[i]], i);
		max_idx[a[i]] = max(max_idx[a[i]], i);
	}
	int p[n];
	for(i=0; i<n; i++) {
		p[i] = -1;
	}
	for(i=0; i<=n; i++) {
		if(min_idx[i] != n && min_idx[i] != max_idx[i]) {
			p[min_idx[i]] = max_idx[i];
		}
		if(max_idx[i] != -1 && min_idx[i] != max_idx[i]) {
			p[max_idx[i]] = min_idx[i];
		}
	}
	/*for(i=0; i<n; i++) {
		printf("%d ", p[i]);
	}
	printf("\n");*/
	int answer = 0;
	for(i=0; i<n; i++) {
		if(p[i] != -1) {
			answer += 2;
			int start = i, end = p[i];
			while(1) {
				int mreach = -1;
				for(j=start+1; j<end; j++) {
					if(p[j] > end && p[j] > mreach) {
						mreach = p[j];
					}
				}
				if(mreach == -1) {
					break;
				} else {
					start = end;
					end = mreach;
					answer++;
				}
			}
			i = end;
		} else {
			answer++;
		}
				//printf("%d %d\n", i, answer);
	}
	answer = n-answer;
	printf("%d\n", answer);
}