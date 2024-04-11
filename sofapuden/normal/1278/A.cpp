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
	string s1, s2;
	cin >> s1 >> s2;
	sort(all(s1));
	if (s1.size() > s2.size()) {
		cout << "NO\n";
	}
	else {
		rep(i, 0, s2.size() - s1.size()+1) {
			string tmp = s2.substr(i, s1.size());
			sort(all(tmp));
			if (tmp == s1) {
				cout << "YES\n";
					return;
			}
		}
		cout << "NO\n";
		return;
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}