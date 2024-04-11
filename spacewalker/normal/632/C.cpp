#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	vector<string> arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr.begin(), arr.end(), [] (string a, string b) {return a + b < b + a;});
	for (int i = 0; i < n; ++i) cout << arr[i];
	return 0;
}