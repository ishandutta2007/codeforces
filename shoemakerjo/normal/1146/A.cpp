#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	int numa = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] =='a') numa++;
	}
	int nota = s.length() - numa;

	int ans = min((int) s.length(), numa + numa-1);

	cout << ans << endl;
}