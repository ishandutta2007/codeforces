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
	string s;
	cin >> s;
	int up = 0, down = 0, right = 0, left = 0;
	for (char ss : s) {
		if (ss == 'U') {
			up++;
		}
		else if(ss == 'D') {
			down++;
		}
		else if (ss == 'R') {
			right++;
		}
		else {
			left++;
		}
	}
	if (min(down, up) == 0&&min(right,left) >= 1) {
		cout << "2\nRL\n";
		return;
	}
	if (min(down, up) >= 1 && min(right, left) == 0) {
		cout << "2\nUD\n";
		return;
	}
	cout << 2 * min(up, down) + 2 * min(right, left) << endl;
	rep(i, 0, min(up, down)) {
		cout << 'U';
	}
	rep(i, 0, min(right, left)) {
		cout << 'R';
	}
	rep(i, 0, min(up, down)) {
		cout << 'D';
	}
	rep(i, 0, min(right, left)) {
		cout << 'L';
	}
	cout << endl;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}