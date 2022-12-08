#include <bits/stdc++.h>

using namespace std;

int freq[27];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	string s;
	cin >> n >> k;
	cin >> s;
	for (int i = 0; i < n; i++) {
		freq[s[i]-'A']++;
	}
	int ans = n;
	for (int i = 0; i < k; i++) {
		ans = min(ans, freq[i]);
	}
	cout << ans*k  << endl;
}