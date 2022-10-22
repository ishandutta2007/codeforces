#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll MAXN = (1LL << 32) - 1;

int main() {
	//freopen("B.in", "r", stdin);
	//freopen("B.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	vector <ll> st;
	st.push_back(1);
	int n;
	cin >> n;
	ll x = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "add") {
			x += st.back();
			if (x > MAXN) {
				cout << "OVERFLOW!!!\n";
				return 0;
			}
		} else if (s == "end") {
			st.pop_back();
		} else {
			ll t;
			cin >> t;
			st.push_back(st.back() * t);
			if (st.back() > MAXN) {
				st[st.size() - 1] = MAXN + 1;
			}
		}
	}
	cout << x << "\n";
}