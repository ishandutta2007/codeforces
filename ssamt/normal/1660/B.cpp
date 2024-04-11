#include <bits/stdc++.h>

using namespace std;

int main() {
	int i, j, k, l;
	int t, n, m, q;
	scanf("%d", &t);
	for(int cl=0; cl<t; cl++) {
		scanf("%d", &n);
		vector<int> a(n);
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a.begin(), a.end(), greater<int>());
		if(n == 1) {
			printf((a[0]==1)?"YES\n":"NO\n");
		} else {
			printf((a[0]-a[1]>1)?"NO\n":"YES\n");
		}
	}
}