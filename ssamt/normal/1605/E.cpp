#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k;
	int t, n, m, q;
	scanf("%d", &n);
	long long a[n], b[n], xa[n] = {}, xb[n] = {};
	for(i=0; i<n; i++) {
		scanf("%lld", &a[i]);
	}
	for(i=0; i<n; i++) {
		scanf("%lld", &b[i]);
	}
	b[0] = 0, xb[0] = 1;
	long long d[n], xd[n];
	for(i=1; i<=n; i++) {
		d[i-1] = b[i-1]-a[i-1];
		xd[i-1] = xb[i-1]-xa[i-1];
		for(j=i; j<=n; j+=i) {
			a[j-1] += d[i-1];
			xa[j-1] += xd[i-1];
		}
	}
	vector<vector<long long>> point;
	long long zero = 0;
	for(i=0; i<n; i++) {
		//printf("%lld %lld\n", xd[i], d[i]);
		if(xd[i] == 0) {
			zero += abs(d[i]);
		} else {
			if(xd[i] < 0) {
				xd[i] = -xd[i];
				d[i] = -d[i];
			}
			point.push_back({-d[i]/xd[i]-1, i});
		}
	}
	sort(point.begin(), point.end());
	long long sum[point.size()+1], xsum[point.size()+1];
	sum[0] = xsum[0] = 0;
	for(i=0; i<point.size(); i++) {
		sum[0] -= d[point[i][1]];
		xsum[0] -= xd[point[i][1]];
	}
	for(i=1; i<=point.size(); i++) {
		sum[i] = sum[i-1]+2*d[point[i-1][1]];
		xsum[i] = xsum[i-1]+2*xd[point[i-1][1]];
	}
	/*for(i=0; i<point.size(); i++) {
		printf("%lld %lld\n", point[i][0], point[i][1]);
	}
	for(i=0; i<=point.size(); i++) {
		printf("%lld %lld\n", xsum[i], sum[i]);
	}*/
	scanf("%d", &q);
	for(ql=0; ql<q; ql++) {
		int x;
		scanf("%d", &x);
		int idx = lower_bound(point.begin(), point.end(), vector<long long>{x, 0})-point.begin();
		printf("%lld\n", xsum[idx]*x+sum[idx]+zero);
	}
}