#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int mod = 1000000007;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> p(n);
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
	}
	int mx = *max_element(p.begin(), p.end());
	vector<bool> isprime(mx + 1);
	for (int i = 2; i <= mx; ++i) isprime[i] = true;
	for (int i = 2; i * i <= mx; ++i) {
		if (!isprime[i]) continue;
		for (int j = i * i; j <= mx; j += i) {
			isprime[j] = false;
		}
	}
	vector<int> primes;
	vector<int> pid(mx + 1, -1);
	for (int i = 2; i <= mx; ++i) {
		if (isprime[i]) {
			pid[i] = primes.size();
			primes.push_back(i);
		}
	}
	vector<int> cnt(primes.size()), top1(primes.size()), top2(primes.size());
	for (int i = 0; i < n; ++i) {
		++cnt[pid[p[i]]];
	}
	vector<bool> pused(primes.size());
	for (int i = primes.size() - 1; i >= 0; --i) {
		if (cnt[i] >= 1 && top1[i] == 0) {
			pused[i] = true;
			top1[i] = 1;
			--cnt[i];
		}
		if (cnt[i] == 0) continue;
		int x = primes[i] - 1;
		for (int j = 0; primes[j] * primes[j] <= x; ++j) {
			int divcnt = 0;
			while (x % primes[j] == 0) {
				x /= primes[j];
				++divcnt;
			}
			if (divcnt > top1[j]) {
				top2[j] = top1[j];
				top1[j] = divcnt;
			}
			else if (divcnt > top2[j]) {
				top2[j] = divcnt;
			}
		}
		if (x > 1) {
			if (top1[pid[x]] == 0) {
				top1[pid[x]] = 1;
			}
			else if (top2[pid[x]] == 0) {
				top2[pid[x]] = 1;
			}
		}
	}
	bool flag = false;
	for (int i = 0; i < primes.size(); ++i) {
		if (cnt[i] == 0) continue;
		if (cnt[i] >= 2) {
			flag = true;
			continue;
		}
		int x = primes[i] - 1;
		bool decrease = false;
		for (int j = 0; primes[j] * primes[j] <= x; ++j) {
			int divcnt = 0;
			while (x % primes[j] == 0) {
				x /= primes[j];
				++divcnt;
			}
			if (divcnt == top1[j] && top1[j] > top2[j]) {
				decrease = true;
			}
		}
		if (x > 1) {
			if (top1[pid[x]] == 1 && top1[pid[x]] > top2[pid[x]]) {
				decrease = true;
			}
		}
		if (!decrease) flag = true;
	}
	for (int i = 0; i < primes.size(); ++i) {
		if (pused[i] && (top1[i] != 1 || top1[i] == top2[i])) {
			flag = true;
		}
	}
	int ans = 1;
	for (int i = 0; i < primes.size(); ++i) {
		for (int j = 0; j < top1[i]; ++j) {
			ans = (long long)(ans) * primes[i] % mod;
		}
	}
	if (flag) ans = (ans + 1) % mod;
	cout << ans << endl;
	return 0;
}