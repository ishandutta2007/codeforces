#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string x;
	cin >> x;
	vector<char> ans;
	bool started = false;
	for (int i = 0; i < x.length(); i++) {
		int cur = x[i] - '0';
		if (cur >= 5 && !(cur==9 && i == 0)) {
			cur  = 9-cur;
		}
		if (cur == 0 && !started) continue;
		started = true;
		char c = '0'+cur;
		ans.push_back(c);
	}
	if (ans.size()==0) ans.push_back(x[x.length()-1]);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
	}
	cout << endl;
	// cin >> x;
}