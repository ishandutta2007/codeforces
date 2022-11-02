#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int a, b, c, n, x; string s;
int main() {
	cin >> a >> b >> c >> n;
	vector<long long> v1, v2;
	v1.push_back(0); int cnt1 = 0;
	v2.push_back(0); int cnt2 = 0;
	for (int i = 0; i < n; i++) {
		cin >> x >> s;
		if (s == "USB") v1.push_back(x), cnt1++;
		else v2.push_back(x), cnt2++;
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	for (int i = 1; i < v1.size(); i++) v1[i] += v1[i - 1];
	for (int i = 1; i < v2.size(); i++) v2[i] += v2[i - 1];
	int p = min(a, cnt1), q = min(b, cnt2);
	int t = min((cnt1 - p) + (cnt2 - q), c);
	long long ret = 1LL << 60;
	for (int i = 0; i <= t; i++) {
		int rp = p + i, rq = q + (t - i);
		if (rp <= cnt1 && rq <= cnt2) {
			ret = min(ret, v1[rp] + v2[rq]);
		}
	}
	cout << p + q + t << ' ' << ret << endl;
	return 0;
}