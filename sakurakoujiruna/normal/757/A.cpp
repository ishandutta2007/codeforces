#include <bits/stdc++.h>
using namespace std;

string t = "Bulbasaur";

int main() {
	ios :: sync_with_stdio(false);
	string s; cin >> s;
	int ans = 1e6L;
	for(char c = 'a'; c <= 'z'; c ++)
		if(count(t.begin(), t.end(), c))
			ans = min(ans, count(s.begin(), s.end(), c) / 
				count(t.begin(), t.end(), c));
	for(char c = 'A'; c <= 'Z'; c ++)
		if(count(t.begin(), t.end(), c))
			ans = min(ans, count(s.begin(), s.end(), c) / 
				count(t.begin(), t.end(), c));
	cout << ans << '\n';
	return 0;
}