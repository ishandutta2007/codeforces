#include <bits/stdc++.h>

using namespace std;

int en[105];
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int garb;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> garb;
		cin >> en[i];
	}
	int sp; cin >> sp;
	int res = 0;
	for (int i = 0; i < n ; i++) {
		if (en[i] >= sp) res++;
	}
	cout << res << endl;
}