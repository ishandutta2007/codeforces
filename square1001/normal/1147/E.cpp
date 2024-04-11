#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const bool debug = false;
string str;
string ask(vector<pair<int, int> > ps) {
	if(!ps.empty()) {
		cout << "Q " << ps.size();
		for(pair<int, int> i : ps) {
			cout << ' ' << i.first + 1 << ' ' << i.second + 1;
		}
		cout << endl;
		string s;
		if(!debug) {
			cin >> s;
		}
		else {
			for(pair<int, int> i : ps) {
				if(str[i.first] == str[i.second]) s += "1";
				else s += "0";
			}
		}
		return s;
	}
	return "";
}
bool validate(int N, vector<vector<int> > ans) {
	vector<vector<int> > g(3);
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < N; ++j) {
			if(str[j] == char(65 + i)) {
				g[i].push_back(j);
			}
		}
	}
	sort(ans.begin(), ans.end());
	sort(g.begin(), g.end());
	return ans == g;
}
int main() {
	int Q;
	cin >> Q;
	while(Q--) {
		int N;
		cin >> N;
		if(debug) {
			str.clear();
			for(int i = 0; i < N; ++i) {
				str += char(rand() % 3 + 65);
			}
		}
		string cont(N - 1, '?');
		for(int i = 0; i < 2; ++i) {
			vector<pair<int, int> > ps;
			for(int j = 0; j < N - 1; ++j) {
				if(j % 2 == i) {
					ps.push_back(make_pair(j, j + 1));
				}
			}
			string s = ask(ps);
			for(int j = 0; j < ps.size(); ++j) {
				cont[ps[j].first] = s[j];
			}
		}
		vector<int> represent;
		represent.push_back(0);
		for(int i = 0; i < N - 1; ++i) {
			if(cont[i] == '0') {
				represent.push_back(i + 1);
			}
		}
		if(debug) {
			cout << "Represent:";
			for(int i : represent) {
				cout << ' ' << i;
			}
			cout << endl;
		}
		string cont2(represent.size(), '?');
		for(int i = 0; i < 2; ++i) {
			vector<pair<int, int> > ps, pt;
			for(int j = 2; j < represent.size(); ++j) {
				if((j % 4) / 2 == i) {
					ps.push_back(make_pair(j - 2, j));
					pt.push_back(make_pair(represent[j - 2], represent[j]));
				}
			}
			string s = ask(pt);
			for(int j = 0; j < ps.size(); ++j) {
				cont2[ps[j].second] = s[j];
			}
		}
		string ans(represent.size(), '?');
		for(int i = 0; i < represent.size(); ++i) {
			if(i <= 1) ans[i] = char(65 + i);
			else if(cont2[i] == '1') ans[i] = ans[i - 2];
			else ans[i] = char(198 - int(ans[i - 1]) - int(ans[i - 2]));
		}
		string fans(N, '?');
		for(int i = 0; i < represent.size(); ++i) {
			fans[represent[i]] = ans[i];
		}
		for(int i = 0; i < N; ++i) {
			if(fans[i] == '?') fans[i] = fans[i - 1];
		}
		vector<vector<int> > v(3);
		for(int i = 0; i < 3; ++i) {
			for(int j = 0; j < N; ++j) {
				if(fans[j] == char(65 + i)) {
					v[i].push_back(j);
				}
			}
		}
		cout << "A " << v[0].size() << ' ' << v[1].size() << ' ' << v[2].size() << endl;
		for(int i = 0; i < 3; ++i) {
			for(int j = 0; j < v[i].size(); ++j) {
				if(j) cout << ' ';
				cout << v[i][j] + 1;
			}
			cout << endl;
		}
		if(debug) {
			cout << "Answer = " << str << endl;
			cout << (validate(N, v) ? "Valid" : "Invalid") << endl;
		}
	}
	return 0;
}