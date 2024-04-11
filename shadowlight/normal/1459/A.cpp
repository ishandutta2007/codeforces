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
	vector <pair <int, int>> a;
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] > t[i]) {
			++cnt1;
		} else if (s[i] < t[i]){
			++cnt2;
		}
	}
	if (cnt1 < cnt2) {
		cout << "BLUE\n";
	} else if (cnt1 > cnt2) {
		cout << "RED\n";
	} else {
		cout << "EQUAL\n";
	}
}

int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}

}