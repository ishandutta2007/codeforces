#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef long double ld;

vector<ll> numset{0}, psum{0};

ld getPreBackAvg(int i) {
    // printf("GPBA %d %lld %d %.1Lf\n", i, psum[i], numset.back(), (i + 1.0L));
	return ((numset.back() + psum[i])/(i + 1.0L));
}

int main() {
	int q; scanf("%d", &q);
	while (q--) {
		int type; scanf("%d", &type);
		if (type == 1) {
			int val; scanf("%d", &val);
			numset.push_back(val);
			psum.push_back((psum.empty() ? 0 : psum.back()) + numset.back());
		} else {
			if (numset.size() == 2) {
				printf("0\n"); continue;
			}
			int lo = 0;
			int hi = (int)numset.size() - 3;
			while (lo < hi) {
				// we are looking for the first i such that
				// (numset.back() + psum[i]) / (i + 1) <= (numset.back() + psum[i+1]) / (i + 2)
				int mid = (lo + hi) / 2;
				// printf("TRY %d VAL %.5Lf %.5Lf\n", mid, (numset.back() + psum[mid])/(mid + 1.0L), (numset.back() + psum[mid+1]) / (mid + 2.0L));
				if (getPreBackAvg(mid) <= getPreBackAvg(mid + 1)) {
					hi = mid;
				} else {
					lo = mid + 1;
				}
			}
			if (getPreBackAvg(lo) <= getPreBackAvg(lo + 1)) {
				// printf("SUCC %d\n", lo);
				printf("%.10lf\n", double(numset.back() - getPreBackAvg(lo)));
			} else {
				printf("%.10lf\n", double(numset.back() - (psum.back() / (ld)(psum.size() - 1))));
			}
		}
	}
	return 0;
}