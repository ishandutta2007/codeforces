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
	int n, k; cin >> n >> k;
	vi v;
	int best = INT_MAX;
	int curr = n;
	rep(i, 0, n) {
		int tmp; cin >> tmp;
		v.push_back(tmp);
	}
	map<int, int> m;
	rep(i, 0, n / 2) {
		m[min(v[i], v[n - i - 1]) + 1]--;
		m[max(v[i], v[n - i - 1]) + k+1]++;
		m[v[i] + v[n - i - 1]]--;
		m[v[i] + v[n - i - 1]+1]++;
	}
	rep(i, 1, k*2+1) {
		curr += m[i];
		best = min(curr, best);
	}
	cout << best << endl;
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