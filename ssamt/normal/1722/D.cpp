#include <bits/stdc++.h>

using namespace std;

int main() {
	int i, j, k, l;
	int t, n, m, q;
	cin >> t;
	for(int cl=0; cl<t; cl++) {
		cin >> n;
		string s;
		cin >> s;
		long long sum = 0;
		vector<int> change;
		for(i=0; i<n; i++) {
			if(s[i] == 'L') {
				sum += i;
				change.push_back(max(0, n-1-i-i));
			} else {
				sum += n-1-i;
				change.push_back(max(0, i-(n-1-i)));
			}
		}
		sort(change.begin(), change.end());
		for(i=0; i<n; i++) {
			sum += change[n-1-i];
			cout << sum << " ";
		}
		cout << endl;
	}
}