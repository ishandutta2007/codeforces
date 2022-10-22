#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int INF = 1e9 + 7;

vector <pair <int, int> > res;
vector <int> a;

void do_swap(int i, int j) {
	res.pb({i, j});
	swap(a[i], a[j]);
}

int main(){
#ifdef LOCAL
	freopen("G_input.txt", "r", stdin);
	//freopen("G_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = n - 1; i >= 0; --i) {
		int x = a[i];
		int pos = -1, minj = INF;
		for (int j = 0; j < i; ++j) {
			if (a[j] > x && minj > a[j]) {
				minj = a[j];
				pos = j;
			}
		}
		if (minj == INF) continue;
		int y = minj;
		do_swap(pos, i);
		for (int j = pos + 1; j < i; ++j) {
			if (a[j] == a[pos]) {
				do_swap(pos, j);
			}
		}
		for (int j = 0; j < i; ++j) {
			if (a[j] == a[i]) {
				do_swap(j, i);
			}
		}
		++i;
	}
	cout << res.size() << "\n";
	for (auto t : res) {
		cout << t.x + 1 << " " << t.y + 1 << "\n";
	}
}