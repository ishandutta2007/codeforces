#include <bits/stdc++.h>

using namespace std;

string alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string alph2 = "abcdefghijklmnopqrstuvwxyz";

string conv(int n) {
	if (n >= 26) {
		
		string ans = "A"+alph2.substr(n-26, 1);
		return ans;
	}
	return alph.substr(n, 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	int nums[n];
	for (int i = 0; i < n; i++) {
		nums[i] = i;
	}
	string tp;
	for (int i = 0; i < n-k+1; i++) {
		cin >> tp;
		if (tp == "NO") {
			nums[i+k-1] = nums[i]; //will not interfere with previous
		}
	}
	for (int i = 0; i < n; i++) {
		string cur = conv(nums[i]);
		cout << cur << " " ;

	}
	cout << endl;
	cin >> n;
}