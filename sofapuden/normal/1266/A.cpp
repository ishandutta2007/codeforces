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
	bool zer = 0;
	bool even = 0;
	int odd = 0;
	int sum = 0;
	rep(i, 0, s.length()) {
		sum += s[i] - '0';
		if (s[i] % 2 == 1) {
			odd++;
		}
		else if (s[i] == '0' && zer == 0) {
			zer = 1;
		}
		else {
			even = 1;
		}
	}
	cout << (zer == 1 && even == 1 && sum % 3 == 0 ? "red\n" : "cyan\n");
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}