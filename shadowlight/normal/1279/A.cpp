#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	vector <int> t = {a, b, c};
	sort(t.begin(), t.end());
	if (t[2] > t[0] + t[1] + 1) {
		cout << "No\n";
	} else {
		cout << "Yes\n";
	}
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
	for (int i = 0; i < t; i++) {
		solve();
	}

}