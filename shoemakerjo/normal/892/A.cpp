#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<ll> caps;
	ll sum = 0LL;
	ll cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		sum += cur;
	}
	for (int i = 0; i < n; i++) {
		cin >> cur;
		caps.push_back(cur);
	}
	sort(caps.begin(), caps.end());
	reverse(caps.begin(), caps.end());
	if (caps[0] + caps[1] >= sum) {
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;
	cin >> n;

}