#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	LL n, k, m;
	cin >> n >> k >> m;
	vector<LL> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	vector<LL> s(n, 0);
	s[0] = v[0];
	for (int i = 1; i < n; i++) {
		s[i] = s[i-1]+v[i];
	}
	double res = 0;
	for (int d = 0; d <= min(m, n-1); d++) {
		// drop the lowest d and increase the rest as much as possible
		LL sum;
		if (d == 0) {
			sum = s[n-1];
		}
		else {
			sum = s[n-1]-s[d-1];
		}
		LL h = n-d; // how many heroes are left
		LL ops = m-d; // how many ops are left
	    //maximum ops we can do is h*k
	    if (h*k <= ops) {
			sum += h*k;
		}
		else {
			// either m is too small or k is too big
			if (ops < h) { // we can't increase all of them so just use up all ops
				sum += ops; // k >= 1
			}
			else { // every h can be incremented at least once.
				// each run of h will use up k ops
				LL x = ops/h;
				x = min(x, k);
				ops -= x*h;
				sum += x*h;
				LL t = k-x;
				if (t > 0) {
					sum += ops;
				}
			}
		}
		res = max(res, double(sum)/h);
	}
	printf("%.10lf\n", res);
	exit(0);
}