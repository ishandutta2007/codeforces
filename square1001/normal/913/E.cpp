#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
string getmin(string s1, string s2) {
	if (s1.size() < s2.size()) return s1;
	if (s1.size() > s2.size()) return s2;
	return min(s1, s2);
}
string getmin(vector<string> v) {
	string ans = v[0];
	for (int i = 1; i < v.size(); ++i) {
		ans = getmin(ans, v[i]);
	}
	return ans;
}
int main() {
	vector<vector<string> > opt(256, vector<string>(3, "Oops, something went wrong! All your bugs are belong to me!"));
	opt[(1 << 4) + (1 << 5) + (1 << 6) + (1 << 7)][0] = "x";
	opt[(1 << 2) + (1 << 3) + (1 << 6) + (1 << 7)][0] = "y";
	opt[(1 << 1) + (1 << 3) + (1 << 5) + (1 << 7)][0] = "z";
	while (true) {
		for (int i = 0; i < 256; ++i) {
			vector<string> nxt(4);
			nxt[0] = getmin({ opt[i][0], "(" + opt[i][1] + ")", "(" + opt[i][2] + ")" });
			nxt[1] = getmin({ opt[i][0], opt[i][1], "(" + opt[i][2] + ")" });
			nxt[2] = getmin({ opt[i][0], opt[i][1], opt[i][2] });
			opt[i] = nxt;
		}
		vector<vector<string> > nxtopt = opt;
		for (int i = 0; i < 256; ++i) {
			nxtopt[255 - i][0] = getmin(nxtopt[255 - i][0], "!" + opt[i][0]);
		}
		for (int i = 0; i < 256; ++i) {
			for (int j = 0; j < 256; ++j) {
				nxtopt[i & j][1] = getmin(nxtopt[i & j][1], opt[i][1] + "&" + opt[j][1]);
				nxtopt[i | j][2] = getmin(nxtopt[i | j][2], opt[i][2] + "|" + opt[j][2]);
			}
		}
		if (opt == nxtopt) break;
		opt = nxtopt;
	}
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		string bitseq;
		cin >> bitseq;
		int bit = 0;
		for (int j = 0; j < 8; ++j) {
			bit += int(bitseq[j] - '0') << j;
		}
		string ans = getmin({ opt[bit][0], opt[bit][1], opt[bit][2] });
		cout << ans << '\n';
	}
	return 0;
}