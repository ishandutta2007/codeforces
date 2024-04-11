#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d", &n);
		priority_queue<int> pq;
		for(i=0; i<n; i++) {
			scanf("%d", &in);
			pq.push(in);
		}
		int find[n+1] = {};
		while(!pq.empty()) {
			int num = pq.top();
			pq.pop();
			if(1<=num && num<=n) {
				if(find[num]) {
					pq.push(num/2);
				} else {
					find[num] = 1;
				}
			} else if(num > n) {
				pq.push(num/2);
			}
		}
		int check = 1;
		for(i=1; i<=n; i++) {
			if(!find[i]) {
				check = 0;
			}
		}
		if(check) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}