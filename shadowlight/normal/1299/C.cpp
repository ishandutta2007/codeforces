#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const db EPS = 1e-9;

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector <pair <db, int> > st;
	for (int i = 0; i < n; i++) {
		db now = a[i];
		int start = i;
		while (st.size() && st.back().x > now) {
			int la = start - st.back().y, lb = i - start + 1;
			db x = st.back().x, y = now;
			now = (x * la + y * lb) / (la + lb);
			start = st.back().y;
			st.pop_back();
		}
		st.push_back({now, start});
	}
	cout.precision(20);
	for (int i = 1; i < (int) st.size(); i++) {
		for (int l = st[i - 1].y; l < st[i].y; l++) {
			cout << st[i - 1].x << "\n";
		}
	}
	for (int l = st.back().y; l < n; l++) {
		cout << st.back().x << "\n";
	}

}