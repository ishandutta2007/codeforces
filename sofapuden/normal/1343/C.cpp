#include<bits/stdc++.h>
#include<unordered_set>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a-1; i>=b; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define LSB(i) ((i) & -(i))
#define MAXSIZE 100000000

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }

void solve() {
	int n; cin >> n;
	bool neg = 0;
	ll best = 0;
	ll sum = 0;

	rep(i, 0, n) {
		ll tmp; cin >> tmp;
		if (tmp > 0) {
			if (neg) {
				sum += best;
				best = tmp;
			}
			else {
				best = max(best, tmp);
			}
			neg = 0;
		}
		else {
			if (!neg) {
				sum += best;
				best = tmp;
			}
			else {
				best = max(best, tmp);
			}
			neg = 1;
		}

	}
	sum += best;
	cout << sum << endl;
	return;
}

int main() {

	ios::sync_with_stdio(0); cin.tie(0);

	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int t; cin >> t;

	while (t--) {
		solve();
	}
	return 0;
}