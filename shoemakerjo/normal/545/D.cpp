#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<ll> v;
	ll cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		v.push_back(cur);
	}
	sort(v.begin(), v.end());
	ll time = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (time <= v[i]) {
			ans++;
			time+=v[i];
		}
	}
	cout << ans << endl;
	cin >> n;

}