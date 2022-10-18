#include <bits/stdc++.h>

using namespace std;
vector<string> split_space(string s)
{
	vector<string> results;
	istringstream fin(s);
	while (!fin.eof())
	{
		string x;
		fin >> x;
		results.push_back(x);
	}
	return results;
}

bool is_suffix(string a, string b) {
	int n = a.size(), m = b.size();
	return n <= m && b.substr(m-n) == a;
}

int main()
{
	int n;
	cin >> n;

	map<string,set<string>> all;
	for (int t = 0; t < n; t++) {
		string s;
		cin >> s;
		int m;
		cin >> m;
		for (int i = 0; i < m; i++) {
			string num;
			cin >> num;
			all[s].insert(num);
		}
	}
	cout << all.size() << endl;
	for (auto p : all) {
		string s = p.first;
		vector<string> z;
		for (auto x : p.second) {
			bool ok = true;
			for (auto y : p.second) {
				if (x != y && is_suffix(x, y)) {
					ok = false;
					break;
				}
			}
			if (ok)
				z.push_back(x);
		}
		cout << s << " " << z.size();
		for (int i = 0; i < z.size(); i++) {
			cout << " " << z[i];
		}
		cout << endl;
	}
	exit(0);
}