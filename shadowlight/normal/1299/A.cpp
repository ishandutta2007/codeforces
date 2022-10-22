#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int LOGN = 30;

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector <int> a(n);
	vector <int> cnt(LOGN, 0);
	vector <int> pos(LOGN, -1);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[i] = x;
		for (int j = 0; j < LOGN; j++) {
			if (x & (1 << j)) {
				cnt[j]++;
				pos[j] = i;
			}
		}
	}
	vector <bool> banned(n, false);
	for (int j = LOGN - 1; j >= 0; j--) {
		if (cnt[j] == 1) {
			int ban = pos[j];
			if (banned[ban]) continue;
			cout << a[ban] << " ";
			banned[ban] = true;
		}
	}
	for (int i = 0; i < n; i++) {
		if (!banned[i]) {
			cout << a[i] << " ";
		}
	}
	cout << "\n";

}