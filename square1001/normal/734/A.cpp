#include <bits/stdc++.h>
using namespace std;
int n; string s;
int main() {
	cin >> n >> s;
	int d = 0, a = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == 'D') d++;
		if(s[i] == 'A') a++;
	}
	if(d > a) cout << "Danik" << endl;
	else if(d < a) cout << "Anton" << endl;
	else cout << "Friendship" << endl;
	return 0;
}