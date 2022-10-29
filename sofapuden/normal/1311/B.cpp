#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a-1; i>=b; i--)
#define makeUnique(vec) sort(all(vec)); vec.resize(unique(all(vec)) - vec.begin())
#define LOG_vec(vec, sep) for (int fl = 0; fl < vec.size(); fl++) { cout << vec[fl]<< sep; } cout << "\n";
#define LOG_ints(vec, sep) for (int fl = 0; fl < MAXSIZE; fl++) { cout << vec[fl]<< sep; } cout << "\n"
#define all(x) (x).begin(), (x).end()
#define LSB(i) ((i) & -(i))
#define MAXSIZE 300000
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
void solve() {
	int n,m;
	cin >> n >> m;
	vi a;
	set<int> p;
	rep(i, 0, n) {
		int tmp; cin >> tmp; a.push_back(tmp);
	}
	rep(i, 0, m) {
		int tmp; cin >> tmp; p.insert(tmp);
	}
	int currmax = 0,oldmax = 0;
	rep(i, 0, n) {
		if (a[i] < oldmax) {
			cout << "NO\n";
			return;
		}
		currmax = max(a[i], currmax);
		if (!p.count(i + 1)) {
			oldmax = currmax;
		}
	}
	cout << "YES\n";
	return;
	
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}