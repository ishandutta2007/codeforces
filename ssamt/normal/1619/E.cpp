#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d", &n);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		int count[n+1] = {};
		for(i=0; i<n; i++) {
			count[a[i]]++;
		}
		sort(a, a+n);
		stack<int> s;
		long long answer = 0;
		printf("%lld ", answer+count[0]);
		int idx = 0;
		for(i=1; i<=n; i++) {
			while(idx < n && a[idx] < i) {
				s.push(a[idx]);
				idx++;
			}
			if(!s.empty()) {
				answer += i-1-s.top();
				s.pop();
				printf("%lld ", answer+count[i]);
			} else {
				for(j=i; j<=n; j++) {
					printf("-1 ");
				}
				break;
			}
		}
		printf("\n");
	}
}