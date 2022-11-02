#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const vector<string> suffix = { "00", "25", "50", "75" };
int main() {
	string s;
	cin >> s;
	if (s.size() == 1) cout << (s == "0" ? "0\n" : "-1\n");
	else {
		int ret = (1 << 30);
		for (string x : suffix) {
			string cur = s;
			int ops = 0;
			for (int i = 1; i >= 0; --i) {
				int pos = -1;
				for (int j = cur.size() - 1; j >= 0; --j) {
					if (cur[j] == x[i]) {
						pos = j;
						break;
					}
				}
				if (pos == -1) {
					ops = (1 << 30);
					break;
				}
				if (pos + 1 == cur.size()) {
					cur.pop_back();
					continue;
				}
				if (pos == 0 && cur[1] == '0') {
					int npos = -1;
					for (int i = 2; i < cur.size(); ++i) {
						if (cur[i] != '0') {
							npos = i;
							break;
						}
					}
					if (npos == -1) {
						ops = (1 << 30);
						break;
					}
					swap(cur[1], cur[npos]);
					ops += npos - 1;
				}
				ops += cur.size() - pos - 1;
				cur = cur.substr(0, pos) + cur.substr(pos + 1, cur.size() - pos - 1);
			}
			ret = min(ret, ops);
		}
		cout << (ret != (1 << 30) ? ret : -1) << '\n';
	}
	return 0;
}