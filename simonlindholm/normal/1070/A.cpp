#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int D;
vector<array<int, 10>> p10s;
vector<map<pii, int>> memo;
int entries;
clock_t start = clock();

void stop() {
	if ((clock() - start) > 2*CLOCKS_PER_SEC || entries > 3'000'000) {
		cout << -1 << endl;
		exit(0);
	}
}

bool rec(int dig, int sum, int mod, bool reconstruct) {
	if (sum < 0) return false;
	if (dig * 9 < sum) return false;
	if (dig == 0) return mod == 0;
	stop();
	auto& re = memo[dig - 1][pii(sum, mod)];
	if (re != 0 && !reconstruct) return re - 1;
	entries++;
	rep(d,0,10) {
		if (rec(dig - 1, sum - d, (mod + p10s[dig - 1][d]) % D, false)) {
			if (reconstruct) {
				cout << d;
				rec(dig - 1, sum - d, (mod + p10s[dig - 1][d]) % D, true);
			}
			re = 2;
			return true;
		}
	}
	re = 1;
	return false;
}

int main() {
	cin.sync_with_stdio(false);
	int S;
	cin >> D >> S;
	vector<int> dp(D);
	dp[0] = 1;
	int pw = 1;
	const int lots = 1'000'000'000; // max(D, S / 9) + 40; // 1'000'000'000;
	rep(le,1,lots) {
		// cerr << le << endl;
		stop();
		array<int, 10> ar;
		rep(i,0,10) ar[i] = pw * i % D;
		p10s.push_back(ar);
		memo.emplace_back();
		pw = pw * 10 % D;
		if (rec(le, S, 0, false)) {
			rec(le, S, 0, true);
			cout << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}