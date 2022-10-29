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
	vi v(3);
	rep(i, 0, 3) {
		cin >> v[i];
	}
	sort(all(v));
	if (v[0] + v[1] >= v[2]) {
		cout << (v[0] + v[1] + v[2]) / 2 << endl;
		return;
	}
	cout << v[0] + v[1] << endl;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}