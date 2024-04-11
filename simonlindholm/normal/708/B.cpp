#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int sq(ll x) {
	ll n = 0;
	while (n * (n-1) / 2 < x) {
		n++;
	}
	if (n * (n-1) / 2 == x) return (int)n;
	throw false;
}

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	ll a00 = 0, a01 = 0, a10 = 0, a11 = 0;
	cin >> a00 >> a01 >> a10 >> a11;
	/*
	{
		string s;
		cin >> s;
		rep(i,0,sz(s)) rep(j,i+1,sz(s)) {
			char a = s[i], b = s[j];
			if (a == '0')
				(b == '0' ? a00 : a01)++;
			else
				(b == '0' ? a10 : a11)++;
		}
	}
	*/

	if (a00 == 0 && a01 == 0 && a10 == 0 && a11 == 0) {
		cout << "1" << endl;
	}
	else {
		try {
			int zeroes = sq(a00), ones = sq(a11);
			if (!zeroes && (a01 || a10)) zeroes++;
			if (!ones && (a01 || a10)) ones++;
			ll len = zeroes + ones;
			if (len * (len-1) / 2 != a00 + a11 + a01 + a10) throw false;
			if (!ones) {
				cout << string(zeroes, '0') << endl;
			}
			else {
				int z = (int)a10;
				string res;
				for (;;) {
					if (z > zeroes) {
						res += '1';
						ones--;
						z -= zeroes;
					}
					else {
						res += string(zeroes - z, '0');
						res += '1';
						res += string(z, '0');
						ones--;
						z = 0;
						break;
					}
				}
				res += string(ones, '1');
				cout << res << endl;
			}
		}
		catch(bool) {
			cout << "Impossible" << endl;
		}
	}
}