#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;
const int N = 200000 + 10;
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int t; cin >> t;
	while (t --) {
		string s; 
		int n;
		cin >> n >> s;

		map<string,bool> m; m.clear();
		for (int i = 0; i < n; i ++) {
			string ans = "";
			for (int j = i; j < min(i + 3, n); j ++) {
				ans += s[j]; m[ans] = true;
			}
		}
		bool done = 0;

		for (char i = 'a'; i <= 'z'; i ++) {
			string ans = "";
			ans += i;
			if (m[ans] == false) {
				cout << ans << endl; done = 1; break;
			}
		}

		if (! done) {

			for (char i = 'a'; i <= 'z'; i ++) for (char j = 'a'; j <= 'z'; j ++){
				if(done) break;
				string ans = "";
				ans += i; ans += j;
				if (m[ans] == false) {
					cout << ans << endl; done = 1; break;
				}
			}

		}
		if (! done) {

			for (char i = 'a'; i <= 'z'; i ++) for (char j = 'a'; j <= 'z'; j ++)for (char k= 'a'; k <= 'z'; k ++){
				if(done) break;
				string ans = "";
				ans += i; ans += j;ans+= k;
				if (m[ans] == false) {
					cout << ans << endl; done = 1; break;
				}
			}

		}
	}
}