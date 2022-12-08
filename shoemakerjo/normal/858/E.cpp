#include <bits/stdc++.h>

using namespace std;

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	int n;
	cin >> n;
	string name;
	int type;
	stack<string> bex;
	stack<string> bre;
	int maxnum = n;
	int taken[n+1];
	for (int i = 0; i <= n; i++) {
		taken[i] = -1;
	}
	int nume = 0;
	for (int i = 0; i < n; i++) {
		cin >> name >> type;
		bool isgood = true;
		if (type == 1) nume++;
		if (name[0] == '0' || name[0]-'0' < 1 || name[0] - '0' > 9) {
			isgood = false;
		}
		for (int i = 1; i < name.length(); i++) {
			if (name[i] - '0' >= 0 && name[i] -'0' <= 9) {
				continue;
			}
			else isgood = false;
		}
		if (isgood) {
			int cur = stoi(name);
			maxnum = max(maxnum, cur);
			if ( cur < 1 || cur > n) isgood = false;
		}
		if (isgood) {
			taken[stoi(name)] = type;
		}
		else {
			if (type == 0) {
				bre.push(name);
			}
			else {
				bex.push(name);
			}
		}
	}
	vector<pair<string, int>> ans;
	stack<int> ae;
	stack<int> ar;
	stack<int> me;
	stack<int> mr;

	for (int i = 1; i <= nume; i++) {
		if (taken[i] == -1) {
			ae.push(i);
		}
		if (taken[i] == 0) mr.push(i);
	}
	for (int i = nume+1; i <= n; i++) {
		if (taken[i] == -1) {
			ar.push(i);
		}
		if (taken[i] == 1) me.push(i);
	}
	while (me.size() > 0 || mr.size() > 0) {
		if (ae.size() > 0 && me.size() > 0) {
			int spot = ae.top(); ae.pop();
			int mov = me.top(); me.pop();
			ar.push(mov);
			ans.push_back(make_pair(to_string(mov), spot));
		}
		else if (ar.size() > 0 && mr.size() > 0) {
			int spot = ar.top(); ar.pop();
			int mov = mr.top(); mr.pop();
			ae.push(mov);
			ans.push_back(make_pair(to_string(mov), spot));
		}
		else {
			int mov = mr.top(); mr.pop();
			int mov2 = me.top(); me.pop();
			ans.push_back(make_pair(to_string(mov), maxnum+1));
			while (me.size() > 0 && mr.size() > 0) {
				// if (me.size() != mr.size()) {
				// 	cout << "wrong";
				// 	return 0;
				// }
				ans.push_back(make_pair(to_string(mov2), mov));
				mov = mr.top(); mr.pop();
				ans.push_back(make_pair(to_string(mov), mov2));
				mov2 = me.top(); me.pop();
			}
			ans.push_back(make_pair(to_string(mov2), mov));
			ans.push_back(make_pair(to_string(maxnum+1), mov2));
		} //
	}
	// cout << "here" << endl;
	while (bre.size() > 0 || bex.size() > 0) {
		if (bre.size() > 0) {
			string temp = bre.top();
			bre.pop();
			int spot = ar.top(); ar.pop();
			ans.push_back(make_pair(temp, spot));
		}
		if (bex.size() > 0) {//
			string temp = bex.top();
			bex.pop();
			int spot = ae.top(); ae.pop();
			ans.push_back(make_pair(temp, spot));
		}
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << "move " << ans[i].first << " " << ans[i].second << endl;
	}
	// cin >> n;
	
}