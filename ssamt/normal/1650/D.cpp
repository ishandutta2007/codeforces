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
		scanf("%d", &n);
		int idx[n];
		for(i=0; i<n; i++) {
			scanf("%d", &in);
			in--;
			idx[in] = i;
		}
		vector<int> answer;
		for(i=n-1; i>=1; i--) {
			answer.push_back((idx[i]+1)%(i+1));
			for(j=i-1; j>=0; j--) {
				idx[j] += i-idx[i];
				idx[j] %= i+1;
			}
		}
		answer.push_back(0);
		for(i=answer.size()-1; i>=0; i--) {
			printf("%d ", answer[i]);
		}
		printf("\n");
	}
}