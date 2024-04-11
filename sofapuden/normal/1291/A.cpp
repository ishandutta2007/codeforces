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

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		string ans = "";
		cin >> s;
		int number = 0;
		rep(i, 0, n) {
			int tmp = s[i];
			if (tmp % 2 == 1) {
				number++;
				if (number == 2) {
					ans += s[i];
					cout << ans << endl;
				}
				ans += s[i];
			}
			else {
				ans += s[i];
			}
			
		}
		if (number < 2) {
			cout << -1 << endl;
		}
	}
}