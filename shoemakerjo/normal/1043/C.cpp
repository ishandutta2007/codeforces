#include <bits/stdc++.h>

using namespace std;
#define maxn 1010

int ans[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	for (int i = 1; i < s.length(); i++) {
		if (s[i] != s[i-1]) ans[i-1] = 1;
	}
	if (s[s.length()-1] == 'a') ans[s.length()-1] = 1;
	for (int i = 0; i < s.length(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	
}