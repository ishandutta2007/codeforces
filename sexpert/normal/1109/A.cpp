#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n), pref(n + 1);
	for(int i = 0; i < n; i++)
	    cin >> v[i];
	for(int i = 1; i <= n; i++)
	    pref[i] = pref[i - 1] ^ v[i - 1];
	//for(int i = 0; i <= n; i++)
	//    cout << pref[i] << " ";
	map<int, long long> ct[2];
	int pt = 0;
	long long ans = 0;
	for(int i = n; i >= 0; i--) {
	    ans += ct[pt][pref[i]];
	    ct[pt][pref[i]]++;
	    pt = 1 - pt;
	}
	cout << ans << endl;
}