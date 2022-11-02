#include <bits/stdc++.h>
using namespace std;

int main() {
	ios :: sync_with_stdio(0);
	string s; cin >> s;
	cout << ((~s.find(string(7, '1')) || ~s.find(string(7, '0'))) ? "YES" : "NO") << '\n';
}