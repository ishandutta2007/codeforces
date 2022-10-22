#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 5e5 + 7;
const int SQ = sqrt(N);

int res[SQ][SQ];
int val[N];

int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 1) {
			val[x] += y;
			for (int i = 1; i < SQ; i++) {
				res[i][x % i] += y;
			}
		} else {
			if (x < SQ) {
				cout << res[x][y] << "\n";
			} else {
				int ans = 0;
				for (int j = y; j < N; j += x) {
					ans += val[j];
				}
				cout << ans << "\n";
			}
		}
	}
}