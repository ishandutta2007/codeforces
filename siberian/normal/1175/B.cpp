#include <bits/stdc++.h>

using namespace std;
#define int long long



void read() {
	int n;
	cin >> n;
	int x = 0;
	int add = 1;
	vector<int> st;
	vector<int> all;
	int INF = pow(2, 32) - 1;
	for (int i = 0; i < n; i++) {
		string type;
		cin >> type;
		if (type == "for") {
			int x;
			cin >> x;
			all.push_back(x);
			if (x != 1)
			st.push_back(x);
		}
		if (type == "end") {
			if (all.back() != 1)
			st.pop_back();
			all.pop_back();
		}
		if (type == "add") {
			int add = 1;
			for (auto j : st) {
				add *= j;
				if (add > INF) {
					cout << "OVERFLOW!!!" << endl;
					exit(0);
				}
			}
			x += add;
		}
	}
	if (x > INF) {
		cout << "OVERFLOW!!!" << endl;
		exit(0);
	}

	cout << x << endl;
}


signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	return 0;
}