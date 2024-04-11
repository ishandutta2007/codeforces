#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const long long limq = 10000;
long long solve(int rem, long long l) {
	if (l >= limq) {
		long long delta = 0;
		for (int i = 1; i <= rem; ++i) {
			delta = delta * (limq + 1) + limq;
		}
		return l + delta;
	}
	if (rem == 1) return l * 2;
	long long cur = l;
	for (int i = 0; i <= l; ++i) {
		cur = solve(rem - 1, cur);
		if (i != l) ++cur;
	}
	return cur;
}
long long getseq(int rem, long long l, int idx) {
	if (rem == 1) return l + idx - 1;
	long long cur = l;
	for (int i = 0; i < idx; ++i) {
		cur = solve(rem - 1, cur) + 1;
	}
	return cur;
}
int main() {
	int rem = 5; long long cur = 1;
	while (true) {
		int num = min(cur, 10000LL);
		cout << num;
		long long icur = cur;
		for (int i = 1; i <= num; ++i) {
			if (rem >= 2) icur = solve(rem - 1, icur);
			cout << ' ' << icur;
			++icur;
		}
		cout << endl;
		int val;
		cin >> val;
		if (val == -1) break;
		cur = getseq(rem, cur, val);
		--rem;
	}
	return 0;
}