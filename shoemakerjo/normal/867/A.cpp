#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >>  n;
	string line;
	cin >> line;
	int s = 0, f = 0;
	for (int i = 0; i < n-1; i++) {
		if (line[i+1] == 'F' && line[i] == 'S') {
			s++;
		}
		else  if (line[i+1] == 'S' && line[i]=='F') {
			f++;
		}
	}
	if (s > f) cout << "YES" << endl;
	else cout << "NO" << endl;
	// cin  >> n;
}