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
	vector <int> a(n), fst(n, INF), lst(n, -1);
	set <int> at;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
		lst[a[i]] = i;
		fst[a[i]] = min(fst[a[i]], i);
		at.insert(a[i]);
	}
	int pr = -1;
	int res = 0;
	int now = 0;
	for (int i = 0; i < n; i++) {
		int l = fst[i], r = lst[i];
		if (l == INF) continue;
		if (l > pr) {
			now++;
			res = max(res, now);
			pr = r;
		} else {
			now = 1;
			res = max(res, now);
			pr = r;
		}
	}
	cout << at.size() - res << "\n";
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		solve();
	}

}