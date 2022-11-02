#include <bits/stdc++.h>

using namespace std;

int main() {
	int i, j, k, l;
	int t, n, m, q;
	int x;
	scanf("%d %d", &n, &x);
	vector<int> count(x+1, 0);
	for(i=0; i<n; i++) {
		int in;
		scanf("%d", &in);
		count[in]++;
	}
	int check = 1;
	for(i=0; i<x; i++) {
		if(count[i]%(i+1) == 0) {
			count[i+1] += count[i]/(i+1);
		} else {
			check = 0;
			break;
		}
	}
	printf(check?"Yes\n":"No\n");
}