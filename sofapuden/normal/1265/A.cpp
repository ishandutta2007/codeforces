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
	if (s[0] == '?') {
		if (s[1] == 'a') {
			s[0] = 'b';
		}
		else {
			s[0] = 'a';
		}
	}
	rep(i, 1, s.length()-1) {
		if (s[i] == '?') {
			if (s[i - 1] != 'a' && s[i + 1] != 'a') {
				s[i] = 'a';
			}
			else if (s[i - 1] != 'b' && s[i + 1] != 'b') {
				s[i] = 'b';
			}
			else if (s[i - 1] != 'c' && s[i + 1] != 'c') {
				s[i] = 'c';
			}
		}

	}
	if (s[s.length()-1] == '?') {
		if (s[s.length()-2] == 'a') {
			s[s.length()-1] = 'b';
		}
		else {
			s[s.length()-1] = 'a';
		}
	}
	char x = 'p';
	rep(i, 0, s.length()) {
		if (s[i] == x) {
			cout << -1 << endl;
			return;
		}
		x = s[i];
	}
	cout << s << endl;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}