#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d %d", &n, &k);
		char s[n+1];
		scanf("%s", s);
		int count[26] = {};
		for(i=0; i<n; i++) {
			count[s[i]-'a']++;
		}
		int pair = 0, sum = 0;
		for(i=0; i<26; i++) {
			pair += count[i]/2;
			sum += count[i];
		}
		int answer = pair/k*2;
		if(sum-answer*k >= k) {
			answer++;
		}
		printf("%d\n", answer);
	}
}