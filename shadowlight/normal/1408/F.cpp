#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int n;

vector <pair <int, int>> res;
vector <int> a;

void do_op(int i, int j) {
	res.pb({i, j});
	int f = max(a[i], a[j]);
	a[i] = f, a[j] = f;
}

int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	a.resize(n, 0);
	iota(all(a), 0);

	int k = 0, now = 1;
	while (2 * now <= n) {
		now *= 2;
		++k;
	}
	int group = 1;
	while (group < now) {
		for (int start = 0; start < now; start += 2 * group) {
			for (int i = 0; i < group; ++i) {
				do_op(start + i, start + i + group);
			}
		}
		group *= 2;
	}

	group = 1;
	while (group < now) {
		for (int start = 0; start < now; start += 2 * group) {
			for (int i = 0; i < group; ++i) {
				do_op((n - 1) - (start + i), (n - 1) - (start + i + group));
			}
		}
		group *= 2;
	}

	/*for (int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
	cout << "\n";*/

	cout << res.size() << "\n";
	for (auto t : res) {
		cout << t.x + 1 << " " << t.y + 1 << "\n";
	}


}