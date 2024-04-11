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
 
int main(){
#ifdef LOCAL
	freopen("L_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector <vector <int> > a(n, vector <int> (m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	int l = -1, r = INF;
	int aa = -1, bb = -1;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		vector <int> masks(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] >= mid) {
					masks[i] |= (1 << j);
				}
			}
		}
		vector <int> have(1 << m, -1);
		for (int i = 0; i < n; i++) {
			have[masks[i]] = i;
		}
		for (int i = (1 << m) - 1; i >= 0; i--) {
			if (have[i] == -1) continue;
			for (int j = 0; j < m; j++) {
				if ((1 << j) & i) {
					have[i ^ (1 << j)] = have[i];
				}
			}
		}
		bool can = false;
		for (int i = 0; i < (1 << m); i++) {
			if (have[i] != -1 && have[(1 << m) - 1 - i] != -1) {
				can = true;
				aa = have[i], bb = have[(1 << m) - 1 - i];
				break;
			}
		}
		if (can) {
			l = mid;
		} else {
			r = mid;
		}
	}
	//cout << l << "\n";
	cout << aa + 1 << " " << bb + 1 << "\n";
}