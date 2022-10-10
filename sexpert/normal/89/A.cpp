#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll m, k;

int main() {
	cin >> n >> m >> k;
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	if(n % 2 == 0) {
		cout << "0\n";
		return 0;
	}
	if(n == 1) {
		cout << min((ll)v[0], m * k) << endl;
		return 0;
	}
	int mn = INT_MAX;
	for(int i = 0; i < n; i += 2)
		mn = min(mn, v[i]);
	cout << min((ll)mn, k * (m/((n+1)/2))) << endl;
}