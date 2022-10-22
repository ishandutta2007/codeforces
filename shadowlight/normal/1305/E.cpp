#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int INF = 1e9;
const int D = 1e4;

bool check(vector <int> &c, int n, int m) {
	if (c.size() != n) return false;
	int pr = -1;
	for (int x : c) {
		if (x < 1 || x > INF) return false;
		if (x < pr) return false;
		pr = x;
	}
	int now = 0;
	for (int i = 0; i < (int) c.size(); i++) {
		for (int j = i + 1; j < (int) c.size(); j++) {
			for (int k = j + 1; k < (int) c.size(); k++) {
				now += (c[i] + c[j] == c[k]);
			}
		}
	}
	return now == m;
}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int cnt = 0;
	vector <int> a(n);
	iota(a.begin(), a.end(), 1);
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			cnt += (i + j <= n);
		}
	}
	if (cnt < m) {
		cout << "-1\n";
		return 0;
	}
	vector <int> b;
	int kek = INF;
	for (int i = n; i >= 1; i--) {
		if (cnt == m) break;
		int d = (i - 1) / 2;
		if (cnt - d >= m) {
			cnt -= d;
			a.pop_back();
			b.push_back(kek);
			kek -= D;
			continue;
		}
		a.pop_back();
		int now = cnt - d;
		for (int x = 1; ; x++) {
			int dd = (i - x - 1) / 2;
			if (now + dd == m) {
				a.pb(i + x);
				break;
			}
		}
		break;
	}

	vector <int> c;
	for (int x : a) {
		cout << x << " ";
		c.pb(x);
	}
	reverse(b.begin(), b.end());
	for (int x : b) {
		cout << x << " ";
		c.pb(x);
	}
	cout << endl;
	//assert(check(c, n, m));
}