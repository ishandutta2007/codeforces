#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAXN = 1e6 + 7;

vector <int> p;
vector <int> d(MAXN, -1);

void sieve() {
	for (int i = 2; i < MAXN; i++) {
		if (d[i] == -1) {
			d[i] = p.size();
			p.push_back(i);
		}
		for (int j = 0; j <= d[i]; j++) {
			if (p[j] * i >= MAXN) break;
			d[p[j] * i] = j;
		}
	}
}

int main() {
	//freopen("A.in", "r", stdin);
	//freopen("A.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	//sieve();
	int n;
	cin >> n;
	int a = 0, b = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 1) {
			a++;
		} else {
			b++;
		}
	}
	vector <int> res;
	if (!b) {
		for (int i = 0; i < a; i++) {
			res.push_back(1);
		}
		a = 0;
	} else {
		res.push_back(2);
		b--;
	}
	if (a) {
		res.push_back(1);
		a--;
	}
	for (int i = 0; i < a / 2; i++) {
		res.push_back(1);
		res.push_back(1);
	}
	a %= 2;
	for (int i = 0; i < b; i++) {
		res.push_back(2);
	}
	if (a) {
		res.push_back(1);
	}
	for (int i = 0; i < n; i++) {
		cout << res[i] << " ";
	}
	cout << "\n";
}