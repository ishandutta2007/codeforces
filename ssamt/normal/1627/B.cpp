#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int u, v;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d %d", &n, &m);
		if(n > m) {
			swap(n, m);
		}
		vector<int> answer;
		if(n%2 == 1 && m%2 == 1) {
			answer.push_back(1);
			for(i=0; i<n/2; i++) {
				answer.push_back(4*i+4);
			}
			for(i=0; i<(m-n)/2; i++) {
				answer.push_back(2*n);
			}
			for(i=n/2; i>=1; i--) {
				answer.push_back(4*i);
			}
		} else if(n%2 == 1 && m%2 == 0) {
			for(i=0; i<=n/2; i++) {
				answer.push_back(4*i+2);
			}
			for(i=0; i<(m-n-1)/2; i++) {
				answer.push_back(2*n);
			}
			for(i=n/2; i>=1; i--) {
				answer.push_back(4*i);
			}
		} else if(n%2 == 0 && m%2 == 1) {
			for(i=0; i<n/2; i++) {
				answer.push_back(4*i+2);
			}
			for(i=0; i<(m-n+1)/2; i++) {
				answer.push_back(2*n);
			}
			for(i=n/2-1; i>=1; i--){
				answer.push_back(4*i);
			}
		} else {
			for(i=0; i<n/2; i++) {
				answer.push_back(4*i+4);
			}
			for(i=0; i<(m-n)/2; i++) {
				answer.push_back(2*n);
			}
			for(i=n/2-1; i>=1; i--){
				answer.push_back(4*i);
			}
		}
		for(i=0; i<answer.size(); i++) {
			for(j=0; j<answer[i]; j++) {
				printf("%d ", n+m-2-((int)answer.size()-i-1));
			}
		}
		printf("\n");
	}
}