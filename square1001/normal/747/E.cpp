#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, cnt, a[500009], d[500009]; string s[500009], t; vector<int> z[500009];
void dfs(int pos, int depth) {
	cnt++; d[pos] = depth; z[depth].push_back(pos);
	for (int i = 0; i < a[pos]; i++) dfs(cnt, depth + 1);
}
int main() {
	cin >> t; t += ',';
	int l = 0, c = 0;
	for (int i = 0; i < t.size(); i++) {
		if (t[i] == ',') {
			if (c & 1) a[c >> 1] = stoi(t.substr(l, i - l));
			else s[c >> 1] = t.substr(l, i - l);
			l = i + 1; c++;
		}
	}
	n = c >> 1;
	while (cnt < n) dfs(cnt, 0);
	int w = *max_element(d, d + n);
	cout << w + 1 << endl;
	for (int i = 0; i <= w; i++) {
		for (int j : z[i]) cout << s[j] << ' ';
		cout << endl;
	}
	return 0;
}