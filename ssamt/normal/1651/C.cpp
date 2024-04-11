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
		scanf("%d", &n);
		long long a[n], b[n];
		for(i=0; i<n; i++) {
			scanf("%lld", &a[i]);
		}
		for(i=0; i<n; i++) {
			scanf("%lld", &b[i]);
		}
		long long answer = INT_MAX;
		vector<long long> sp{a[0], a[n-1], b[0], b[n-1]};
		vector<long long> corr;
		sort(a, a+n);
		sort(b, b+n);
		int idx;
		for(i=0; i<2; i++) {
			idx = lower_bound(b, b+n, sp[i])-b;
			long long asv = abs(sp[i]-b[idx]);
			if(idx != 0) {
				asv = min(asv, abs(sp[i]-b[idx-1]));
			}
			corr.push_back(asv);
		}
		for(i=2; i<4; i++) {
			idx = lower_bound(a, a+n, sp[i])-a;
			long long asv = abs(sp[i]-a[idx]);
			if(idx != 0) {
				asv = min(asv, abs(sp[i]-a[idx-1]));
			}
			corr.push_back(asv);
		}
		answer = min(answer, abs(sp[0]-sp[3])+abs(sp[1]-sp[2]));
		answer = min(answer, abs(sp[0]-sp[2])+abs(sp[1]-sp[3]));
		answer = min(answer, abs(sp[0]-sp[3])+corr[1]+corr[2]);
		answer = min(answer, abs(sp[0]-sp[2])+corr[1]+corr[3]);
		answer = min(answer, abs(sp[1]-sp[3])+corr[0]+corr[2]);
		answer = min(answer, abs(sp[1]-sp[2])+corr[0]+corr[3]);
		answer = min(answer, corr[0]+corr[2]+corr[1]+corr[3]);
		printf("%lld\n", answer);
	}
}