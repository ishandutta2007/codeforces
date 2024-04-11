#include <cstdio>
#include <vector>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
const int bits = 30;
int minxor(vector<int> &va, vector<int> &vb, int val, int var, int vbl, int vbr, int depth) {
	if (depth == -1) return 0;
	for (int i = val; i < var; ++i) va[i] &= (2 << depth) - 1;
	for (int i = vbl; i < vbr; ++i) vb[i] &= (2 << depth) - 1;
	int vas = lower_bound(va.begin() + val, va.begin() + var, 1 << depth) - va.begin();
	int vbs = lower_bound(vb.begin() + vbl, vb.begin() + vbr, 1 << depth) - vb.begin();
	int ret = (1 << depth);
	if ((vas == val || vbs == vbl) && (vas == var || vbs == vbr)) {
		if (vas != val && vbs != vbr) ret = min(ret, minxor(va, vb, val, vas, vbs, vbr, depth - 1));
		if (vas != var && vbs != vbl) ret = min(ret, minxor(va, vb, vas, var, vbl, vbs, depth - 1));
		ret += 1 << depth;
	}
	else {
		if (vas != val && vbs != vbl) ret = min(ret, minxor(va, vb, val, vas, vbl, vbs, depth - 1));
		if (vas != var && vbs != vbr) ret = min(ret, minxor(va, vb, vas, var, vbs, vbr, depth - 1));
	}
	return ret;
}
long long solve(vector<int> v, int depth) {
	if (depth == -1) return 0;
	vector<int> va, vb;
	for (int i = 0; i < v.size(); ++i) {
		if ((v[i] >> depth) & 1) vb.push_back(v[i]);
		else va.push_back(v[i]);
	}
	if (va.empty() || vb.empty()) return solve(v, depth - 1);
	long long ret = 0;
	ret += solve(va, depth - 1);
	ret += solve(vb, depth - 1);
	ret += minxor(va, vb, 0, va.size(), 0, vb.size(), bits - 1);
	return ret;
}
int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a.begin(), a.end());
	long long ret = solve(a, bits - 1);
	printf("%lld\n", ret);
	return 0;
}