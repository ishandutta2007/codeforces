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
	int n;
	cin >> n;
	string s;
	cin >> s;

	int cnt = 0;
	while (s.size() && s.back() == ')') {
		++cnt;
		s.pop_back();
	}
	if (2 * cnt > n) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
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
	for (int i = 0; i < t; ++i) {
		solve();
	}

}