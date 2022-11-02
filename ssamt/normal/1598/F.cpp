#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k;
	int t, n, m, q;
	scanf("%d", &n);
	string s[n];
	for(i=0; i<n; i++) {
		cin >> s[i];
	}
	int dx[n];
	vector<int> low[n];
	for(i=0; i<n; i++) {
		int count = 0;
		int h = 0;
		int lowest = 0;
		for(char c:s[i]) {
			if(c == '(') {
				h++;
			} else {
				h--;
			}
			if(h == lowest) {
				count++;
			} else if(h < lowest) {
				low[i].push_back(count);
				count = 1;
				lowest = h;
			}
		}
		low[i].push_back(count);
		dx[i] = h;
	}
	/*for(i=0; i<n; i++) {
		printf("%d\n", dx[i]);
		for(j=0; j<low[i].size(); j++) {
			printf("%d ", low[i][j]);
		}
		printf("\n");
	}*/
	vector<int> d[1<<n]; // height, found, possible
	int answer = 0;
	d[0] = {0, 0, 1};
	for(t=1; t<(1<<n); t++) {
		d[t] = {0, 0, 0};
		for(i=0; i<n; i++) {
			if(t&(1<<i)) {
				int last = t-(1<<i);
				if(d[last][2]) {
					if(d[last][0]-((int)low[i].size()-1) >= 0) {
						//printf("!%d %d %d\n", i, t, last);
						d[t][0] = d[last][0]+dx[i];
						d[t][1] = max(d[t][1], d[last][1]);
						d[t][2] = 1;
						if(d[last][0]-((int)low[i].size()-1) == 0) {
							d[t][1] = max(d[t][1], d[last][1]+low[i].back());
						}
					} else {
						answer = max(answer, d[last][1]+low[i][d[last][0]]);
					}
				}
			}
		}
		//printf("%d: %d %d %d\n", t, d[t][0], d[t][1], d[t][2]);
	}
	if(d[(1<<n)-1][2]) {
		answer = max(answer, d[(1<<n)-1][1]);
	}
	printf("%d\n", answer);
}