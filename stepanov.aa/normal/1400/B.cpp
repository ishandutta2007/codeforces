#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	long long t;
	cin >> t;;
	for (long long c = 0; c < t; ++c) {
		long long p, f;
		cin >> p >> f;
		long long cnts, cntw;
		cin >> cnts >> cntw;
		long long s, w;
		cin >> s >> w;
		if (s > w) {
			swap(s, w);
			swap(cnts, cntw);
		}
		long long res = 0;
		long long m = min(p / s, cnts);
		for (long long i = 0; i <= m; ++i) {
			long long r = i + (p - i * s) / w;
			long long cs = cnts - i;
			long long cw = cntw - (p - i * s) / w;
			r += min(f / s, cs) + min((f - min(f / s, cs) * s) / w, cw);
			res = max(res, r);
			
		}
		cout << res << endl;
	}
	return 0;
}