#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i ++)
using namespace std;
const int mx = 1000005;
#define endl '\n'
typedef long long LL;
typedef pair<int, int> pii;

vector<int> V[4];
vector<int> R;
vector<int> L;
int x[mx], t[mx];
char d[mx][2];

int main() {

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int Tc;
	for (cin >> Tc; Tc--; ) {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) cin >> x[i];
		for (int i = 1; i <= n; i++) cin >> d[i];
		for (int i = 1; i <= n; i++) t[i] = -1;
		V[0].clear(); V[1].clear();
		for (int i = 1; i <= n; i++) V[x[i] & 1].push_back(i);
		for (int k = 0; k < 2; k++) {
			R.clear(); L.clear();
			sort(V[k].begin(), V[k].end(), [](int i1, int i2) { return x[i1] < x[i2]; } );
			for (int j = 0; j < V[k].size(); j++) {
				int i = V[k][j];
				if (d[i][0] == 'R') R.push_back(i);
				else {
					if (!R.empty()) {
						int i1 = R.back(), i2 = i;
						R.pop_back();
						t[i1] = t[i2] = abs(x[i1] - x[i2]) / 2;
					}
					else L.push_back(i);
				}
			}
			for (int i = 0; i + 1 < L.size(); i += 2) {
				int i1 = L[i], i2 = L[i + 1];
				t[i1] = t[i2] = (x[i1] + x[i2]) / 2;
			}
			for (int i = R.size() - 1; i - 1 >= 0; i -= 2) {
				int i1 = R[i - 1], i2 = R[i];
				t[i1] = t[i2] = (2 * m - x[i1] - x[i2]) / 2;
			}
			if (L.size() % 2 && R.size() % 2) {
				int i1 = L[L.size() - 1], i2 = R[0];
				t[i1] = t[i2] = (m + x[i1] + (m - x[i2])) / 2;
			}
		}
		for (int i = 1; i <= n; i++) cout << t[i] << ' '; cout << endl;
	}
	
	return 0;

}