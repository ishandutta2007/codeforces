#include <vector>
#include <iostream>
using namespace std;
int a, b, p, inv[1000009], ok[1000009]; long long x;
int extgcd(int a, int b, int &x, int &y) {
	int g = a; x = 1; y = 0;
	if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
	return g;
}
int main() {
	cin >> a >> b >> p >> x; x++;
	inv[1] = 1;
	for (int i = 2; i < p; i++) inv[i] = 1LL * inv[p % i] * (p - p / i) % p;
	for (int i = 0; i < p; i++) ok[i] = -1;
	vector<int> v;
	int mul = 1;
	while (true) {
		ok[mul] = v.size();
		v.push_back(mul);
		mul = 1LL * mul * a % p;
		if (mul == 1) break;
	}
	long long loop = 1LL * p * v.size();
	if (loop <= 10000000) {
		long long ret = 0;
		for (int i = 0; i < loop; i++) {
			int val = 1LL * (i % p) * (v[i % v.size()]) % p;
			if (val == b) ret += x / loop;
			if (val == b && i < x % loop) ret++;
		}
		cout << ret << endl;
	}
	else {
		long long ret = 0;
		for (int i = 1; i < p; i++) {
			if (ok[i] == -1) continue;
			int val = 1LL * b * inv[i] % p, rvx, rvy;
			extgcd(p, v.size(), rvx, rvy);
			long long vx = rvx, vy = rvy;
			vx *= ok[i] - val;
			vy *= ok[i] - val;
			if (vx < 0) vx = (v.size() - (-vx) % v.size()) % v.size();
			if (vy < 0) vy = (p - (-vy) % p) % p;
			vx %= p;
			vy %= p;
			long long rv = 1LL * vx * p + val;
			ret += x / loop + (x % loop > rv);
		}
		cout << ret << endl;
	}
	return 0;
}