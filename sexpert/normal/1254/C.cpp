#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll area[1005];
int n;

ll ask(int t, int i, int j, int k) {
	cout << t << " " << i << " " << j << " " << k << '\n';
	cout.flush();
	ll ans;
	cin >> ans;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	int s = 2;
	for(int p = 3; p <= n; p++) {
		if(ask(2, 1, p, s) == 1)
			s = p;
	}
	// 1 -- s is a side
	vector<int> rest;
	for(int p = 2; p <= n; p++) {
		if(p == s)
			continue;
		area[p] = ask(1, 1, s, p);
		rest.push_back(p);
	}
	sort(rest.begin(), rest.end(), [&](int i, int j){ 
		return area[i] < area[j];
	});
	int q = rest.back();
	// 1 -- s -- q has max area
	vector<int> ri, le;
	for(int i = 0; i < rest.size() - 1; i++) {
		if(ask(2, s, rest[i], q) == 1)
			ri.push_back(rest[i]);
		else
			le.push_back(rest[i]);
	}
	reverse(le.begin(), le.end());
	cout << "0 1 " << s << " ";
	for(auto p : ri)
		cout << p << " ";
	cout << q << " ";
	for(auto p : le)
		cout << p << " ";
	cout << '\n';
	cout.flush();
}