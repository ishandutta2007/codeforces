#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false;

string res[N][2];
int prVal[N][2];
int prInd[N][2];

void solve() {
	string s;
	cin >> s;
	int n = s.length();

	for (int i = 0; i <= n; i++) {
		res[i][0] = res[i][1] = "";
		prVal[i][0] = prVal[i][1] = 0;
		prInd[i][0] = prInd[i][1] = 0;
	}

	res[0][0] = res[0][1] = (s[0] == 'a' ? "a" : "b");

	for (int i = 1; i < n; i++) {
		string mn = res[i - 1][0] + s[i];
		string mx = res[i - 1][1] + s[i];
		string mn_r = mn;
		string mx_r = mx;
		reverse(mn_r.begin(), mn_r.end());
		reverse(mx_r.begin(), mx_r.end());

		if (mn < mx_r) {
			res[i][0] = mn;
			prVal[i][0] = 0;
			prInd[i][0] = 0;
		} else {
			res[i][0] = mx_r;
			prVal[i][0] = 1;
			prInd[i][0] = 1;
		}

		if (mx > mn_r) {
			res[i][1] = mx;
			prVal[i][1] = 0;
			prInd[i][1] = 1;
		} else {
			res[i][1] = mn_r;
			prVal[i][1] = 1;
			prInd[i][1] = 0;
		}
	}

	vector<int> ans;
	int ind = 0;

	for (int i = n - 1; i >= 0; i--) {
		ans.push_back(prVal[i][ind]);
		ind = prInd[i][ind];
	}

	for (int i = n - 1; i >= 0; i--) {
		cout << ans[i] << " ";
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	tst = 6;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}