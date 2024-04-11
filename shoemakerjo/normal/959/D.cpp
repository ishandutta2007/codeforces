#include <bits/stdc++.h>

using namespace std;

vector<int> primes;
bool is_comp[2000010];
int di[2000010];

void sieve() {
	fill(is_comp, is_comp+200010, false);
	for (int i = 2; i <= 2000000; i++) {
		if (!is_comp[i]) {
			primes.push_back(i);
			di[i] = primes.size()-1;
		}
		for (int j = 0; j < primes.size() && i * primes[j] <= 2000000; j++) {
			is_comp[i * primes[j]] = true;
			di[i * primes[j]] = j;
			if (i % primes[j] == 0) break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	sieve();
	int n;
	cin >> n;
	int nums[n];
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	int ans[n];
	bool lex = false;
	int minaval = 0;
	int cs = primes.size();
	bool take[cs];
	fill(take, take+cs, false);
	for (int i = 0; i < n; i++) {
		if (lex) {
			while (take[minaval]) {
				minaval++;
			}
			take[minaval] = true;
			cout << primes[minaval] << " ";
		}
		else {
			bool fin = false;
			int cur = nums[i];
			// if (i == n-1) cur++;
			while (!fin) {
				vector<int> pc;
				int tmp = cur;
				bool ok = true;
				while (tmp > 1) {
					pc.push_back(di[tmp]);
					if (take[di[tmp]]) ok = false;
					tmp /= primes[di[tmp]];
				}
				if (ok) {
					fin = true;
					for (auto v : pc) take[v] = true;
				}
				else {
					 cur++;
				}

			}
			if (cur > nums[i]) lex = true;
			cout << cur << " ";
		}
	}
	cout << endl;
	cin >> n;
}