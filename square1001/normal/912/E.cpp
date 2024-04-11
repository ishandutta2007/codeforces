#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const long long global_limit = 1000000000000000000;
vector<long long> enumerate(vector<int> p, long long limit) {
	vector<long long> gen = { 1 };
	for (int i : p) {
		vector<long long> nxt;
		for (long long j : gen) {
			long long cur = j;
			while (cur <= limit) {
				nxt.push_back(cur);
				if (log(cur) + log(i) > log(limit) + 0.01) break;
				cur *= i;
			}
		}
		gen = nxt;
	}
	sort(gen.begin(), gen.end());
	return gen;
}
int main() {
	int N; long long K;
	cin >> N;
	vector<int> P(N);
	for (int i = 0; i < N; ++i) cin >> P[i];
	cin >> K;
	sort(P.begin(), P.end());
	vector<int> lp, rp;
	for (int i = 0; i < N; ++i) {
		if (i % 4 == 0 || i % 4 == 3) lp.push_back(P[i]);
		else rp.push_back(P[i]);
	}
	vector<long long> genl = enumerate(lp, global_limit);
	vector<long long> genr = enumerate(rp, global_limit);
	vector<double> lgenl(genl.size()), lgenr(genr.size());
	for (int i = 0; i < genl.size(); ++i) lgenl[i] = log(genl[i]);
	for (int i = 0; i < genr.size(); ++i) lgenr[i] = log(genr[i]);
	double loglim = log(global_limit);
	long long l = 0, r = global_limit + 1;
	while (r - l > 1) {
		long long m = (l + r) >> 1;
		int ptr = genr.size();
		long long sum = 0;
		for (long long i = 0; i < genl.size(); ++i) {
			while (ptr != 0 && (lgenl[i] + lgenr[ptr - 1] > loglim + 0.01 || genl[i] * genr[ptr - 1] > m)) --ptr;
			sum += ptr;
		}
		if (sum < K) l = m;
		else r = m;
	}
	cout << r << endl;
	return 0;
}