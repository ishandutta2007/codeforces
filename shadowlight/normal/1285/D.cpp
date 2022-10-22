#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;



int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector <int> a(n);
	int res = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector <vector <int> > g;
	g.push_back(a);
	for (int i = 29; i >= 0; i--) {
		vector <vector <int> > ng;
		bool good = false;
		for (auto mas : g) {
			vector <int> na, nb;
			int cnt = 0;
			for (int x : mas) {
				if ((1 << i) & x) {
					cnt++;
				}
			}
			//cout << i << " " << cnt << " " << mas.size() << "\n";
			if (!cnt || cnt == mas.size()) {
				good = true;
				break;
			}
		}
		if (!good) {
			res ^= (1 << i);
		}
		for (auto mas : g) {
			vector <int> na, nb;
			int cnt = 0;
			for (int x : mas) {
				if ((1 << i) & x) {
					na.push_back(x);
				} else {
					nb.push_back(x);
				}
			}
			if (!na.size() || !nb.size()) {
				ng.push_back(mas);
			} else if (!good) {
				ng.push_back(na);
				ng.push_back(nb);
			}
		}
		g = ng;
	}
	cout << res << "\n";
}