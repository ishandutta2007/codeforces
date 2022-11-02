#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;
		string s = "";
		for (int j = 0; j < n - 2; ++j)
			s += '0';
		s += "11";
		for (int j = 0; j < n; ++j) {
			for (auto c : s) {
				cout << c << " ";
			}
			cout << "\n";
			string s2 = s;
			s2.pop_back();
			s = s.back() + s2;
		}
	}
	return 0;
}