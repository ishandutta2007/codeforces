#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector <pair <int, int> > ded;

int sq(int i, int j, int k) {
	int xa = ded[j].first - ded[i].first;
	int ya = ded[j].second - ded[i].second;
	int xb = ded[k].first - ded[i].first;
	int yb = ded[k].second - ded[i].second;
	return xa * yb - xb * ya;
}

ll query(int tp, int a, int b, int c) {
	cout << tp << " " << a << " " << b << " " << c << endl;
	/*ll x = sq(a - 1, b - 1, c - 1);
	if (tp == 2) {
		x = (x > 0 ? 1 : -1);
	} else {
		x = abs(x);
	}*/
	ll x;
	cin >> x;
	return x;
}

vector <ll> S;

bool cmp(int i, int j) {
	return S[i] < S[j];
}

void normalize(vector <int> &tet, int s, int t) {
	if (!tet.size()) {
		return;
	}
	sort(tet.begin(), tet.end(), cmp);
	int val = tet.back();
	vector <int> left, right;
	//cout << val << "\n";
	for (int x : tet) {
		if (x == val) continue;
		if (query(2, s + 1, val + 1, x + 1) == -1) {
			right.push_back(x);
		} else {
			left.push_back(x);
		}
	}
	sort(left.rbegin(), left.rend(), cmp);
	sort(right.begin(), right.end(), cmp);
	tet.clear();
	for (int x : right) {
		tet.push_back(x);
	}
	tet.push_back(val);
	for (int x : left) {
		tet.push_back(x);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	/*ded.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> ded[i].first >> ded[i].second;
	}*/

	vector <int> up, down;

	S.resize(n, 0);

	for (int i = 2; i < n; i++) {
		S[i] = query(1, 1, 2, i + 1);
		ll sgn = query(2, 1, 2, i + 1);
		if (sgn == 1) {
			up.push_back(i);
		} else {
			down.push_back(i);
		}
	}
	normalize(up, 0, 1);
	normalize(down, 1, 0);
	vector <int> res = {0};
	for (int x : down) {
		res.push_back(x);
	}
	res.push_back(1);
	for (int x : up) {
		res.push_back(x);
	}
	cout << "0 ";
	for (int x : res) {
		cout << x + 1 << " ";
	}
	cout << endl;
}