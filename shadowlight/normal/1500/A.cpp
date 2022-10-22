#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int MAXN = 5e6 + 7;

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector <pair <int, int> > a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].x;
		a[i].y = i;
	}
	sort(all(a));
	map <int, vector<int>> cnt;
	for (auto t : a) {
		cnt[t.x].pb(t.y);
	}
	vector <int> twos;
	int mx = 0;
	vector<int> value;
	for (auto t : cnt) {
		if (t.y.size() >= 2) {
			for (int i = 0; i < 2; ++i) {
				twos.pb(t.y[i]);
			}
		}
		if (t.y.size() > mx) {
			mx = t.y.size();
			value = t.y;
		}
	}
	if (mx >= 4) {
		cout << "YES\n";
		for (int i = 0; i < 4; ++i) {
			cout << value[i] + 1 << " ";
		}
		cout << "\n";
		return 0;
	}
	if (twos.size() >= 4) {
		cout << "YES\n";
		cout << twos[0] + 1 << " " << twos[2] + 1 << " " << twos[1] + 1 << " " << twos[3] + 1 << "\n";
		return 0;
	}
	int forb1 = -1, forb2 = -1;
	if (mx >= 2) {
		forb1 = value[1];
		if (mx == 3) {
			forb2 = value[2];
		}
	}
	//cout << forb1 << " " << forb2 << endl;
	vector <pair <int, int>> have(MAXN, {-1, -1});
	for (int i = 0; i < n; ++i) {
		int x = a[i].x, indx = a[i].y;
		for (int j = i + 1; j < n; ++j) {
			int y = a[j].x, indy = a[j].y;
			if ((indx == forb1 || indy == forb1) && (x != y || (indx + indy == forb1 + forb2))) continue;
			if ((indx == forb2 || indy == forb2) && (indx + indy != forb1 + forb2)) continue;
			//cout << indx << " " << indy << endl;
			if (have[x + y].x != -1) {
				cout << "YES\n";
				cout << indx + 1 << " " << indy + 1 << " ";
				cout << have[x + y].x + 1 << " " << have[x + y].y + 1 << "\n";
				return 0;
			}
			have[x + y] = {indx, indy};
		}
	}
	cout << "NO\n";
}