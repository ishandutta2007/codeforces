#include <bits/stdc++.h>

using namespace std;

#define INF 10000000
#define pii pair<int, int>

int main() {
	string line;
	cin >> line;
	int curch = -1;
	int csize = 0;
	int n = line.length();
	vector<pii> blk;
	for (int i = 0; i < n; i++) {
		int ch = line[i]-'a';
		if (ch == curch) {
			csize++;
		}
		else {
			if (curch != -1) {
				blk.push_back(pii(curch, csize));
			}
			curch = ch;
			csize = 1;
		}
	}
	blk.push_back(pii(curch, csize));
	vector<pii> nb;
	int ans = 0;
	while (blk.size() > 1) {
		// cout << "here   " << blk.size() << endl;
		ans++;
		nb.clear();
		for (int i = 0; i < blk.size(); i++) {
			int ch = blk[i].first;
			int cs = blk[i].second;
			// cout << ch << " -  " << cs << endl;
			if (i == 0) {
				if (cs > 1) {
					nb.push_back(pii(ch, cs-1));
				}
			}
			else if (i == blk.size()-1) {
				if (cs > 1) {
					nb.push_back(pii(ch, cs-1));
				}
			}
			else {
				if (cs > 2) {
					nb.push_back(pii(ch, cs-2));
				}
			}
		}
		if (nb.size() <= 1) break;
		curch = -1;
		csize = 0;
		blk.clear();
		// cout << "sz  " << blk.size() << endl;
		for (int i = 0; i < nb.size(); i++) {
			int ch = nb[i].first;
			int cs = nb[i].second;
			if (ch == curch) {
				csize += cs;
			}
			else {
				if (curch != -1) {
					blk.push_back(pii(curch, csize));
				}
				curch = ch;
				csize = cs;
			}
		}
		blk.push_back(pii(curch, csize));

	}
	cout << ans << endl;
	cin >> ans;
}