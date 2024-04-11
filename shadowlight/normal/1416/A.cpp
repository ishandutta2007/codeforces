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

void solve() {
	int n;
	cin >> n;
	vector <int> a(n);
	map <int, int> pr;
	map <int, int> mx;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (!pr.count(a[i])) {
			pr[a[i]] = -1;
		}
		mx[a[i]] = max(mx[a[i]], i - pr[a[i]]); 
		pr[a[i]] = i;
	}
	vector <int> res(n + 1, INF);
	for (auto t : mx) {
		int x = t.x, y = t.y;
		y = max(y, n - pr[x]);
		//cout << x << " " << y << endl;
		res[y] = min(res[y], x);
	}

	for (int i = 0; i < n; ++i) {
		res[i + 1] = min(res[i + 1], res[i]);
		cout << (res[i + 1] == INF ? -1 : res[i + 1]) << " ";
	}
	cout << "\n";

}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		solve();
	}


}