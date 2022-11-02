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
		int a[n+1][3];
		for(i=0; i<3; i++) {
			a[0][i] = 0;
		}
		vector<int> pos;
		for(i=1; i<=n; i++) {
			for(j=0; j<3; j++) {
				a[i][j] = a[i-1][j];
			}
			a[i][s[i-1]-'a']++;
			if(s[i-1] == 'a') {
				pos.push_back(i-1);
			}
		}
		int answer = n+1;
		for(i=0; i<(int)pos.size()-1; i++) {
			int start = pos[i];
			int end = pos[i+1]+1;
			if(a[end][0]-a[start][0] > a[end][1]-a[start][1] && a[end][0]-a[start][0] > a[end][2]-a[start][2]) {
				answer = min(answer, end-start);
			}
		}
		for(i=0; i<(int)pos.size()-2; i++) {
			int start = pos[i];
			int end = pos[i+2]+1;
			if(a[end][0]-a[start][0] > a[end][1]-a[start][1] && a[end][0]-a[start][0] > a[end][2]-a[start][2]) {
				answer = min(answer, end-start);
			}
		}
		if(answer == n+1) {
			printf("-1\n");
		} else {
			printf("%d\n", answer);
		}
	}
}