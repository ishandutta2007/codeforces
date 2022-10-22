#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	//freopen("B.in", "r", stdin);
	//freopen("B.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	ll sum = 0;
	vector <int> last;
	for (int i = 0; i < (int) s.size(); i++) {
		if (s[i] == 'v') {
			if (i != 0 && s[i - 1] == 'v') {
				last.back()++;
			} else {
				last.push_back(1);
			}
		}
	}
	for (ll x : last) {
		sum += x - 1;
	}
	int id = 0;
	ll pref = 0;
	ll res = 0;
	for (int i = 0; i < (int) s.size(); i++) {
		if (s[i] == 'o') {
			if (i && s[i - 1] == 'v') {
				ll x = last[id++];
				pref += x - 1;
				sum -= x - 1;
			}
			res += sum * pref;
		}
	}
	cout << res << "\n";
}