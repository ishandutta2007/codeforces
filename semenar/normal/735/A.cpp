#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	bool pos = false;
	int cur_pos;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'T') {
			pos = true;
		}
		if (s[i] == 'G') {
			cur_pos = i;
			break;
		}
	}
	while (cur_pos >= 0 && cur_pos < s.size() && s[cur_pos] != 'T' && s[cur_pos] != '#') {
		cur_pos += (pos ? -1 : 1)*k;
	}
	if (cur_pos < 0 || cur_pos >= s.size() || s[cur_pos] == '#') {
		cout << "NO";
	}
	else {
		cout << "YES";
	}
	return 0;
}