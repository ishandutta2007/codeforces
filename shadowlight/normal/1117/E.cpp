#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll TESTS = 1;
const int Q = 26;

int main() {
	string t;
	cin >> t;
	int n = t.size();
	vector <int> lens = {n};
	vector <int> what(n, 0);
	for (int i = 0; i < 3; i++) {
		int l = 0;
		vector <int> nlens;
		vector <vector <int> > posd;
		vector <int> wh1(n);
		string q = ""; 
		for (int x : lens) {
			posd.push_back({});
			int r = l + x - 1, l1 = l + x;
			int y = x / Q + 1;
			for (char c = 'a'; l <= r; l += y, c++) {
				for (int d = 0; d < min(y, r - l + 1); d++) {
					q += c;
				}
				nlens.push_back(min(y, r - l + 1));
				posd.back().push_back(nlens.size() - 1);
			}
			l = l1;
		}
		cout << "? " << q << endl;
		string x;
		cin >> x;
		for (int j = 0; j < n; j++) {
			wh1[j] = posd[what[j]][x[j] - 'a'];
		}
		lens = nlens;
		what = wh1;
	}
	assert(lens.size() == n);
	string s;
	for (int i = 0; i < n; i++) {
		s += "#";
	}
	for (int i = 0; i < n; i++) {
		s[what[i]] = t[i];
	}
	cout << "! " << s << endl;
}