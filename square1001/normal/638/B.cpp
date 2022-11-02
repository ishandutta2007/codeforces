#include <string>
#include <vector>
#include <iostream>
using namespace std;
int n; string s; bool used[33], indeg[33]; int edge[33];
int main() {
	cin >> n;
	fill(edge, edge + 26, -1);
	for (int i = 0; i < n; i++) {
		cin >> s; used[s[0] - 97] = true;
		for (int j = 1; j < s.size(); j++) {
			edge[s[j - 1] - 97] = s[j] - 97;
			indeg[s[j] - 97] = true;
		}
	}
	string ret;
	for (int i = 0; i < 26; i++) {
		if (used[i] && !indeg[i]) {
			int pos = i;
			while (pos != -1) {
				ret += pos + 97;
				pos = edge[pos];
			}
		}
	}
	cout << ret << endl;
	return 0;
}