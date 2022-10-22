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
string s;

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector <int> g;
	int now = s[0] - 'A', cnt = 1;
	for (int i = 1; i < n; i++) {
		if (now != s[i] - 'A') {
			g.push_back(cnt);
			cnt = 1;
			now = s[i] - 'A';
		} else {
			cnt++;
		}
	}
	g.push_back(cnt);
	ll res = (ll) n * (n + 1) / 2;
	res -= n;
	for (int i = 0; i < (int) g.size(); i++) {
		if (i != 0) {
			res -= g[i - 1];
		}
		if (i != (int) g.size() - 1) {
			res -= g[i + 1];
		}
	}
	res += (int) g.size() - 1;
	cout << res << "\n";
}