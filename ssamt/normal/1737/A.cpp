#include <bits/stdc++.h>

using namespace std;

int main() {
	int i, j, k, l;
	int t, n, m, q;
	scanf("%d", &t);
	for(int cl=0; cl<t; cl++) {
		scanf("%d %d", &n, &k);
		string s;
		cin >> s;
		vector<int> count(26, 0);
		for(i=0; i<n; i++) {
			count[s[i]-'a']++;
		}
		vector<int> mex(k, 0);
		for(i=0; i<26; i++) {
			for(j=0; j<min(count[i], k); j++) {
				if(mex[j] == i) {
					mex[j]++;
				}
			}
		}
		for(i=0; i<k; i++) {
			printf("%c", min(mex[i], n/k)+'a');
		}
		printf("\n");
	}
}