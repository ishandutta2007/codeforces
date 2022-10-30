#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d", &n);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a, a+n);
		vector<int> c{0};
		for(i=0; i<n; i++) {
			if(i == 0 || a[i-1] != a[i]) {
				c.push_back(c.back()+1);
			} else {
				c.back()++;
			}
		}
		int x, y, z;
		int answer = INT_MAX;
		for(x=1; x<2*n; x*=2) {
			int i = upper_bound(c.begin(), c.end(), x)-c.begin()-1;
			for(y=1; y<2*n; y*=2) {
				int j = upper_bound(c.begin(), c.end(), y+c[i])-c.begin()-1;
				for(z=1; z<n-c[j]; z*=2);
				//printf("%d %d %d %d %d\n", x, y, z, c[i], c[j]);
				answer = min(answer, (x-c[i])+(y-(c[j]-c[i]))+(z-(n-c[j])));
			}
		}
		printf("%d\n", answer);
	}
}