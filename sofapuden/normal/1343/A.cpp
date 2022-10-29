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
	ll n; cin >> n;
	for (int i = 4; i <= n+1; i += i) {
		if (n % (i - 1) == 0) { cout << n / (i - 1) << endl; return; }
	}
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