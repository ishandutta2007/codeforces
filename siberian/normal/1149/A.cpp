#include <bits/stdc++.h>

using namespace std;
#define int long long
#define double long double
int n;
int cnt1 = 0, cnt2 = 0;
vector <int> prime;
void read() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 1)
			cnt1++;
		else
			cnt2++;
	}
	for (int i = 1; i < 2 * n; i++) {

	}



}
vector <int> ans;
void run() {
	int n = 1e6;
	vector<char> prime (n+1, true);
	prime[0] = prime[1] = false;
	for (int i=2; i<=n; ++i)
		if (prime[i])
			if (i * 1ll * i <= n)
				for (int j=i*i; j<=n; j+=i)
					prime[j] = false;

	int sum = 0;
	while (cnt1 && cnt2) {
		if (prime[sum + 1]) {
			cnt1--;
			sum += 1;
			ans.push_back(1);
		}
		else {
			cnt2--;
			sum += 2;
			ans.push_back(2);
		}
	}

	while (cnt1) {
		cnt1--;
		ans.push_back(1);
	}

	while (cnt2) {
		cnt2--;
		ans.push_back(2);
	}
}

void write() {
	for (auto i : ans)
		cout << i << " ";
	cout << endl;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	read();
	run();
	write();
	return 0;
}