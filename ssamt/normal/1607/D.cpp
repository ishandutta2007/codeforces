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
		int a[n];
		char s[n+1];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		scanf("%s", s);
		vector<int> red, blue;
		for(i=0; i<n; i++) {
			if(s[i] == 'R') {
				red.push_back(a[i]);
			} else {
				blue.push_back(a[i]);
			}
		}
		sort(red.begin(), red.end());
		sort(blue.begin(), blue.end());
		int answer = 1;
		for(i=0; i<red.size(); i++) {
			if(red[red.size()-1-i] > n-i) {
				answer = 0;
			}
		}
		for(i=0; i<blue.size(); i++) {
			if(blue[i] < i+1) {
				answer = 0;
			}
		}
		if(answer) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}