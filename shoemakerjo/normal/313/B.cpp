#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;

	int n = s.length();

	int m; cin >> m;

	int prefix[n+1];
	prefix[0] = 0;
	prefix[1] = 0;
	for (int i = 2; i <= n; i++) {
		prefix[i] = prefix[i-1];
		if (s[i-2]==s[i-1]) prefix[i]++;
	}
	int l, r;
	for (int i = 0;  i < m; i++) {
		cin >> l >> r;
		cout << prefix[r]-prefix[l] << endl;
	}
	cin >> n;
}