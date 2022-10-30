#include <bits/stdc++.h>

using namespace std;

int main() {
	int i, j, k, l;
	int t, n, m, q;
	cin >> t;
	for(int cl=0; cl<t; cl++) {
		cin >> n;
		vector<int> a(n);
		for(i=0; i<n; i++) {
			cin >> a[i];
		}
		int answer = a[n-1]-a[0];
		if(n > 1) {
			answer = max(answer, *max_element(a.begin()+1, a.end())-a[0]);
			answer = max(answer, a[n-1]-*min_element(a.begin(), a.end()-1));
			for(i=0; i<n-1; i++) {
				answer = max(answer, a[i]-a[i+1]);
			}
		}
		cout << answer << endl;
	}
}