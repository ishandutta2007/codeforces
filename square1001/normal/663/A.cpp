#include <string>
#include <vector>
#include <iostream>
using namespace std;
int main() {
	string s;
	int plus = 1, minus = 0;
	vector<string> op = { "+" };
	while (true) {
		cin >> s;
		if (s == "?") {
			string x;
			cin >> x;
			if (x == "+") ++plus;
			if (x == "-") ++minus;
			if (x != "=") op.push_back(x);
		}
		else break;
	}
	int n = stoi(s);
	int right = plus * n - minus, left = plus - minus * n;
	cout << (left <= n && n <= right ? "Possible\n" : "Impossible\n");
	if (left <= n && n <= right) {
		vector<int> ans(op.size(), 1);
		int cur = plus - minus, ppos = 0, mpos = 0;
		while (cur != n) {
			if (cur < n) {
				while (op[ppos] == "-" || ans[ppos] == n) ++ppos;
				++ans[ppos];
				++cur;
			}
			else {
				while (op[mpos] == "+" || ans[mpos] == n) ++mpos;
				++ans[mpos];
				--cur;
			}
		}
		for (int i = 0; i < op.size(); ++i) {
			if (i >= 1) cout << op[i] << " ";
			cout << ans[i] << " ";
		}
		cout << "= " << n << endl;
	}
	return 0;
}