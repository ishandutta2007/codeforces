#include <bits/stdc++.h>

using namespace std;

#define maxn 5010

int nums[maxn]; //store the modified version of this
int ans[maxn];
bool curin[maxn];
set<int> seen;
const int inf = 2000000000;
map<int, int> de;

bool isprime(int u) {
	if (u == 1) return false;
	for (int i = 2; i <= sqrt(u); ++i) {
		if (u% i == 0) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> primes;
	for (int i = 2; i <= 20000; i++) {
		if (isprime(i)) primes.push_back(i);
	}

	int cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		int ov = cur;
		int prod = 1;
		if (cur < 0) {
			prod*=-1;
			cur*=-1;
		}
		int ct;
		for (int j = 0; j < primes.size(); ++j) {
			if (primes[j] > cur) break;
			ct = 0;
			while (cur%primes[j] == 0) {
				cur/=primes[j];
				++ct;
			}
			if (ct%2 == 1) prod*=primes[j];
		}
		prod *= cur;
		nums[i] = prod;
		if (ov == 0) nums[i] = inf;
		// cout << i << ": " << nums[i] << endl;
		seen.insert(nums[i]);
	}
	fill(ans, ans+maxn, false);
	int ind = 0;
	for (auto val : seen) {
		de[val] = ind++;
	}
	for (int i = 0; i < n; i++) {
		nums[i] = de[nums[i]]; 
	}

	int zspot = -1;
	if (de.find(inf) != de.end()) zspot = de[inf];
	for (int i = 0; i < n; i++) {
		fill(curin, curin+maxn, false);
		int cans = 0;
		for (int j = i; j < n; j++) {
			if (!curin[nums[j]]) {
				curin[nums[j]] = true;
				cans++;
			}
			if (zspot != -1 && curin[zspot]) {
				if (cans == 1) {
					ans[cans]++;
				}
				else ans[cans-1]++;
			}
			else ans[cans]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";

	}
	cout << endl;
	cin >> cur;


}