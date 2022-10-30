#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	long long i, j, k, l;
	int t, n, m, q;
	int u, v;
	int in;
	cin >> t;
	for(cl=0; cl<t; cl++) {
		cin >> n;
		vector<long long> a;
		for(i=0; i<n; i++) {
			cin >> in;
			a.push_back(in);
		}
		sort(a.begin(), a.end());
		long long answer = LLONG_MIN;
		long long mult = 0;
		long long coef = 0;
		for(i=1; i<n; i++) {
			mult += a[0]*a[i];
			coef += a[0]+a[i];
		}
		if(coef > 0) {
			answer = LLONG_MAX;
		}
		answer = max(answer, coef*(-a[0])+mult);
		for(i=0; i<n-1; i++) {
			if(i > 0) {
				mult -= a[0]*a[i];
				mult += a[n-1]*a[i];
				coef -= a[0];
				coef += a[n-1];
			}
			if(coef > 0) {
				answer = max(answer, coef*(-a[i])+mult);
			} else {
				answer = max(answer, coef*(-a[i+1])+mult);
			}
		}
		if(coef < 0) {
			answer = LLONG_MAX;
		}
		answer = max(answer, coef*(-a[n-1])+mult);
		if(answer == LLONG_MAX) {
			cout << "INF" << endl;
		} else {
			cout << answer << endl;
		}
	}
}