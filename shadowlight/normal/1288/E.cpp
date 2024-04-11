#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

struct Tree {
	int n;
	vector <int> t;
	Tree(int n) : t(2 * n, 0), n(n) {}
	void change(int v, int x) {
		v += n;
		t[v] = x;
		v /= 2;
		while (v > 0) {
			t[v] = t[2 * v] + t[2 * v + 1];
			v /= 2;
		}
	}
	int get(int l, int r) {
		int sum = 0;
		for (l += n, r += n; l <= r; l /= 2, r /= 2) {
			if (l % 2 == 1) {
				sum += t[l++];
			}
			if (r % 2 == 0) {
				sum += t[r--];
			}
		}
		return sum;
	}
};

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector <int> minw(n, 0), maxw(n, 0);
	for (int i = 0; i < n; i++) {
		minw[i] = i + 1, maxw[i] = i + 1;
	}
	vector <int> a(m);
	vector <int> last(n, -1);
	Tree was(n), ones(m);
	for (int i = 0; i < m; i++) {
		cin >> a[i];
		a[i]--;
		was.change(a[i], 1);
		if (last[a[i]] == -1) {
			maxw[a[i]] += was.get(a[i] + 1, n - 1);
		} else {
			maxw[a[i]] = max(maxw[a[i]], ones.get(last[a[i]], m - 1));
			ones.change(last[a[i]], 0);
		}
		last[a[i]] = i;
		ones.change(i, 1);
		minw[a[i]] = 1;
	}
	for (int i = 0; i < n; i++) {
		if (last[i] == -1) {
			maxw[i] += was.get(i + 1, n - 1);
		} else {
			maxw[i] = max(maxw[i], ones.get(last[i], m - 1));
		}
	}
	for (int i = 0; i < n; i++) {
		cout << minw[i] << " " << maxw[i] << "\n";
	}

}