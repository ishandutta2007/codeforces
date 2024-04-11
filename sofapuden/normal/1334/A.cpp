#include<bits/stdc++.h>
#include<unordered_set>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a; i>b; i--)
#define makeUnique(vec) sort(all(vec)); vec.resize(unique(all(vec)) - vec.begin())
#define LOG_vec(vec, sep) for (int fl = 0; fl < vec.size(); fl++) { std::cout << vec[fl]<< (fl == vec.size()-1?"\n":sep;)}
#define LOG_ints(vec, sep) for (int fl = 0; fl < MAXSIZE; fl++) { std::cout << vec[fl]<< sep; } std::cout << "\n"
#define all(x) (x).begin(), (x).end()
#define LSB(i) ((i) & -(i))
#define MAXSIZE 100000

using namespace std;
typedef long long ll;
typedef vector<int> vi;

void solve() {
	int n; cin >> n;
	vector<pair<int, int>> vp(n);
	rep(i, 0, n) {
		cin >> vp[i].first >> vp[i].second;
	}
	int att = 0, clear = 0;
	rep(i, 0, vp.size()) {
		int tmp1, tmp2;
		tmp1 = vp[i].first - att;
		tmp2 = vp[i].second - clear;
		if (tmp1 < 0 || tmp2 < 0 || tmp1 < tmp2) {
			cout << "NO\n";
			return;
		}
		att +=tmp1;
		clear += tmp2;
	}
	cout << "YES\n";
	return;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		solve();
	}
}