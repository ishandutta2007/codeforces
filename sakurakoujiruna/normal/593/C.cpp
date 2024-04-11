#include <bits/stdc++.h>
using namespace std;

const int N = 53;
int x[N], y[N], r[N];

string a(string a, string b) {
	return "(" + a + "+" + b + ")";
}
string m(string a, string b) {
	return "(" + a + "-" + b + ")";
}
string mul(string a, string b) {

	return "(" + a + "*" + b + ")";
}
string ab(string a) {
	return "abs(" + a + ")";
}

string solve(int x[], int n) {
	string ret = "";
	for(int i = 0; i < n; i ++) {
		x[i] /= 2;
		string xsi = m("t", to_string(i));
		string now = a(ab(a(xsi, "1")),
			m(ab(m(xsi, "1")), ab(a(xsi, xsi))));
		now = mul(now, to_string(x[i]));
		if(ret == "") ret = now;
		else ret = a(ret, now);
	}
	return ret;
}

int main() {
	ios :: sync_with_stdio(false);
	int n; cin >> n;
	for(int i = 0; i < n; i ++)
		cin >> x[i] >> y[i] >> r[i];
	cout << solve(x, n) << '\n';
	cout << solve(y, n) << '\n';
	return 0;
}