#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int cost = 0;
	int n;
	cin >> n;
	string a;
	string b;
	cin >> a >> b;
	vector<int> vals; //push back runs
	int crun = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) cost++;
	}
	for (int i = 0; i < n-1; i++) {
		if (a[i] != b[i] && a[i+1] != b[i+1] && a[i] != a[i+1]) {
			cost--;
			i++;
		}
	}
	cout << cost << endl;
}