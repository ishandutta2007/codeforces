#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> s;
	int nmov = (n - 11)/2;

	int sp = -1;
	int ec = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '8') {
			ec++;
			if (ec == nmov+1) {
				sp = i;
			}
		}
	}
	if (sp == -1) {
		cout << "NO" << endl;
		return 0;
	}
	//have sp before sp
	if (sp > 2*nmov) {
		cout << "NO" << endl;
	}
	else cout << "YES" << endl;
}