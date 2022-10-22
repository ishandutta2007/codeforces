#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 2e5 + 7;
vector <int> a;
int n, k;

int res;

vector <pair <int, int> > merge(vector <pair <int, int> > &a, vector <pair <int, int> > &b) {
	int n = a.size(), m = b.size();
	vector <pair <int, int> > res;
	int i = 0, j = 0;
	while (i < n && j < m) {
		if (i == n) {
			res.push_back(b[j++]);
		} else if (j == m) {
			res.push_back(a[i++]);
		} else if (a[i] > b[j]) {
			res.push_back(b[j++]);
		} else {
			res.push_back(a[i++]);
		}
	}
	return res;
}

int x[MAXN], y[MAXN];

bool can(int d) {
	for (int i = 0; i < n; i++) {
		x[i] = a[i] - d;
		y[i] = a[i] + d;
	}
	int cnt = 0, i = 0, j = 0;
	while (i < n && j < n) {
		if (i == n) {
			cnt--;
			j++;
		} else if (j == n) {
			cnt++;
			
			if (cnt >= k) {
				res = x[i];
				return true; 
			}

			i++;
		} else if (x[i] > y[j]) {
			cnt--;
			j++;
		} else {
			cnt++;

			if (cnt >= k) {
				res = x[i];
				return true; 
			}

			i++;
		}
	}

	res = -1;
	return false;
}

void solve() {
	cin >> n >> k;
	k++;	
	a.clear();
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int l = -1, r = INF;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		if (can(mid)) {
			r = mid;
		} else {
			l = mid;
		}
	}
	can(r);
	cout << res << "\n";
}

int main() {
	//freopen("C.in", "r", stdin);
	//freopen("C.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 0 ; i < t; i++) {
		solve();
	}
}