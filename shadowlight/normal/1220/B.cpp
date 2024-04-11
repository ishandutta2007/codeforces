#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector <vector <int> > a;
int n;

bool check(int x) {
	vector <int> t(n);
	t[0] = x;
	for (int i = 1; i < n; i++) {
		if (a[0][i] % x) {
			return false;
		}
		t[i] = a[0][i] / x;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (t[i] * (ll) t[j] != (ll) a[i][j]) {
				return false;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << t[i] << " ";
	}
	cout << "\n";
	exit(0);
	return true;
}

const int INF = 1e9 + 7;

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	a.resize(n, vector <int> (n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	for (int d = 1; d <= sqrt(INF); d++) {
		if (a[0][1] % d) continue;
		check(d);
		check(a[0][1] / d);
	}
}