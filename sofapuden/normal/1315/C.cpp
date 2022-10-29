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
	int n;
	cin >> n;
	set<int> taken;
	vi b;
	vi a;
	rep(i, 0, n) {
		int tmp;
		cin >> tmp;
		b.push_back(tmp);
		taken.insert(tmp);
	}
	rep(i, 0, n) {
		bool ok = 0;
		a.push_back(b[i]);
		rep(j, a[i * 2]+1, n*2+1) {
			if (!taken.count(j)) {
				a.push_back(j);
				ok = 1;
				taken.insert(j);
				break;
			}
		}
		if (!ok) {
			cout << -1 << endl;
			return;
		}
	}
	rep(i, 0, a.size()) {
		cout << a[i] << " ";
	}
	cout << endl;
	return;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}