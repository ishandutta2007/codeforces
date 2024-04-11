#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a-1; i>=b; i--)
#define makeUnique(vec) sort(all(vec)); vec.resize(unique(all(vec)) - vec.begin())
#define LOG_vec(vec, sep) for (int fl = 0; fl < vec.size(); fl++) { cout << vec[fl]<< sep; } cout << "\n";
#define LOG_ints(vec, sep) for (int fl = 0; fl < MAXSIZE; fl++) { cout << vec[fl]<< sep; } cout << "\n"
#define all(x) (x).begin(), (x).end()
#define LSB(i) ((i) & -(i))
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
void solve() {
	const int MOD = 998244353;
	int n, k;
	cin >> n >> k;
	ll max = 0;
	ll counter = 1;
	ll sum = 0;
	rep(i, 0, n) {
		int tmp; cin >> tmp;
		if (tmp > n - k) {
			sum += tmp;
			if (max == 0) {
				max = 1;
				counter = 1;
			}
			max *= counter;
			max %= MOD;
			counter = 1;
		}
		else {
			counter++;
		}
	}
	cout << sum << " " << max << endl;
}
int main() {
	int t = 1;
	while (t--) {
		solve();
	}
}