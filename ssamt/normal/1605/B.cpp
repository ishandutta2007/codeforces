#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k;
	int t, n, m, q;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d", &n);
		char s[n+1];
		scanf("%s", s);
		int a[n];
		for(i=0; i<n; i++) {
			a[i] = s[i]-'0';
		}
		int sorted = 1;
		for(i=0; i<n-1; i++) {
			if(a[i] > a[i+1]) {
				sorted = 0;
			}
		}
		if(sorted) {
			printf("0\n");
		} else {
			int right = 0;
			for(i=0; i<n; i++) {
				if(a[i] == 0) {
					right++;
				}
			}
			vector<int> answer;
			for(i=0; i<right; i++) {
				if(a[i] == 1) {
					answer.push_back(i);
				}
			}
			for(i=right; i<n; i++) {
				if(a[i] == 0) {
					answer.push_back(i);
				}
			}
			printf("1\n");
			printf("%d ", answer.size());
			for(i=0; i<answer.size(); i++) {
				printf("%d ", answer[i]+1);
			}
			printf("\n");
		}
	}
}