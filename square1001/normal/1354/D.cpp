#include <map>
#include <set>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
const int lim = 1048576;
int bit[1048588];
void add(int pos, int val) {
	for (int i = pos; i <= lim; i += i & (-i)) {
		bit[i] += val;
	}
}
int bsearch(int x) {
	if (x == 0) return 0;
	int ptr = 0;
	for (int i = lim / 2; i >= 1; i >>= 1) {
		if (bit[ptr + i] < x) {
			x -= bit[ptr + i];
			ptr += i;
		}
	}
	return ptr + 1;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, Q;
	cin >> N >> Q;
	for (int i = 0; i < N; ++i) {
		int x;
		cin >> x;
		add(x, 1);
	}
	int cnt = N;
	for (int i = 0; i < Q; ++i) {
		int x;
		cin >> x;
		if (x >= 0) add(x, 1), ++cnt;
		else {
			int ptr = bsearch(-x);
			add(ptr, -1);
			--cnt;
		}
	}
	if (cnt == 0) {
		cout << 0 << endl;
	}
	else {
		cout << bsearch(1) << endl;
	}
	return 0;
}