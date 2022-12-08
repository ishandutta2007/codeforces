#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	string s;
	cin >> n >> s;
	map<string, int> freq;
	string ans = "AA";
	int most = 0;
	for (int i = 0; i < n-1; i++) {
		string cur = s.substr(i, 2);
		freq[cur]++;
		if (freq[cur] > most) {
			most = freq[cur];
			ans = cur;
		}
	}
	cout << ans << endl;
	cin >> n;
}