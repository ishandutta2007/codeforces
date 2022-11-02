#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k;
	int t, n, m, q;
	double p;
	scanf("%d %lf", &n, &p);
	for(i=0; i<=n; i++) {
		double prob = 0;
		prob += (double)i*(i-1)*(i-2)/6;
		prob += (double)i*(i-1)*(n-i)/2;
		prob += (double)i*(n-i)*(n-i-1)/4;
		prob /= (double)n*(n-1)*(n-2)/6;
		//printf("%f\n", prob);
		if(prob >= p) {
			break;
		}
	}
	printf("%d\n", i);
}