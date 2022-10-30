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
		int a[m];
		for(i=0; i<m; i++) {
			scanf("%d", &a[i]);
		}
		sort(a, a+m);
		vector<int> d;
		for(i=0; i<m-1; i++) {
			if(a[i+1]-a[i] > 0) {
				d.push_back(a[i+1]-a[i]-1);
			}
		}
		d.push_back(n+a[0]-a[m-1]-1);
		sort(d.begin(), d.end());
		int answer = 0;
		int sub = 0;
		for(i=(int)d.size()-1; i>=0; i--) {
			int left = d[i]-2*sub;
			if(left >= 3) {
				sub += 2;
			} else if(left > 0) {
				sub++;
			}
			int add = left-1;
			if(left == 1) {
				add++;
			}
			if(add > 0) {
				answer += add;
			}
		}
		printf("%d\n", n-answer);
	}
}