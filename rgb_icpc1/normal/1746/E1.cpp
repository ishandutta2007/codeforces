#include <bits/stdc++.h>
using namespace std;

template<typename hd, typename tl> void chkmin(hd& a, tl b) { if(b < a) a = b; }
template<typename hd, typename tl> void chkmax(hd& a, tl b) { if(a < b) a = b; }
#define pb push_back
#define pob pop_back
#define endl '\n'
using LL = long long;
using PI = pair<int, int>;
using VI = vector<int>;
const int MX = 1000005;

string query(VI v, int a, int b) {
	cout << '?' << ' ' << b - a + 1;
	for (int i = a; i <= b; i ++) cout << ' ' << v[i];
	cout << endl;
	cout.flush();
	string s;
	cin >> s;
	return s;
}

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin);
#endif

	int n; cin >> n;
	VI v;
	for (int i = 1; i <= n; i ++) v.pb(i);
	while (1) {
		int m = v.size();
		if (m <= 3) {
			string A, B, s;
			A = query(v, 0, 0);
			if (A[0] == 'Y') {
				cout << "! " << v[0] << endl;
				cout.flush();
				cin >> s;
				if (s[1] == ')') goto ne;
				A = query(v, 1, 1);
				if (A[0] == 'Y') {
					cout << "! " << v[1] << endl;
					cout.flush();
					cin >> s;
					goto ne;
				} else {
					cout << "! " << v[2] << endl;
					cout.flush();
					cin >> s;
					goto ne;
				}
			}
			B = query(v, 0, 0);
			if (A[0] == 'N' && B[0] == 'N') {
				cout << "! " << v[1] << endl;
				cout.flush();
				string s; cin >> s;
				if (s[1] == ')') goto ne;
				cout << "! " << v[2] << endl;
				cout.flush();
				cin >> s;
				goto ne;
			} else {
				cout << "! " << v[0] << endl;
				cout.flush();
				cin >> s;
				if (s[1] == ')') goto ne;
				A = query(v, 1, 1);
				if (A[0] == 'Y') {
					cout << "! " << v[1] << endl;
					cout.flush();
					cin >> s;
					goto ne;
				} else {
					cout << "! " << v[2] << endl;
					cout.flush();
					cin >> s;
					goto ne;
				}
			}
		}
		int e = m / 4;
		int a = 0, b = e, c = 2 * e, d = e * 3;
		VI va, vb, vc, vd;
		for (int i = 0; i < b; i ++) va.pb(v[i]);
		for (int i = b; i < c; i ++) vb.pb(v[i]);
		for (int i = c; i < d; i ++) vc.pb(v[i]);
		for (int i = d; i < m; i ++) vd.pb(v[i]);
		string A, B;
		A = query(v, 0, c - 1);
		B = query(v, b, d - 1);
		int f;
		v.clear();
		if (A[0] == 'Y' && B[0] == 'Y') {
			v = va;
			for (int x : vb) v.pb(x);
			for (int x : vc) v.pb(x);
		}
		if (A[0] == 'Y' && B[0] == 'N') {
			v = va;
			for (int x : vb) v.pb(x);
			for (int x : vd) v.pb(x);
		}
		if (A[0] == 'N' && B[0] == 'Y') {
			v = vb;
			for (int x : vc) v.pb(x);
			for (int x : vd) v.pb(x);
		}
		if (A[0] == 'N' && B[0] == 'N') {
			v = va;
			for (int x : vc) v.pb(x);
			for (int x : vd) v.pb(x);
		}
	}
	ne:;
	return 0;
}