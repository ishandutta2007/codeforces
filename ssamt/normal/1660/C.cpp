#include <bits/stdc++.h>

using namespace std;

int main() {
	int i, j, k, l;
	int t, n, m, q;
	scanf("%d", &t);
	for(int cl=0; cl<t; cl++) {
		string s;
		cin >> s;
		n = s.size();
		vector<int> last(n);
		for(i=0; i<26; i++) {
			int prev = -1;
			for(j=0; j<n; j++) {
				if(s[j] == 'a'+i) {
					last[j] = prev;
					prev = j;
				}
			}
		}
		vector<int> d(n+1);
		d[0] = 0;
		for(i=1; i<=n; i++) {
			d[i] = d[i-1]+1;
			if(last[i-1] != -1) {
				d[i] = min(d[i], d[last[i-1]]+(i-1-last[i-1]-1));
			}
		}
		printf("%d\n", d[n]);
	}
}