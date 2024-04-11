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
	freopen("G_input.txt", "r", stdin);
	//freopen("G_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, a, b;
	cin >> n >> a >> b;
	string s;
	cin >> s;
	vector <int> vals;

	int cnt = 0;
	map <char, int> num;
	string tt = "";
	for (int i = 0; i < n; ++i) {
		char c = s[i];
		if (!num.count(c)) {
			num[c] = cnt++;
			tt += c;
		}
		vals.pb(num[c]);
	}

	vector <int> lt(cnt, -1), rt(cnt, -1);
	vector <int> copies(cnt, 0);
	for (int i = 0; i < n; ++i) {
		int x = vals[i];
		if (lt[x] == -1) {
			lt[x] = i;
		}
		rt[x] = max(rt[x], i);
		++copies[x];
	}

	vector <int> dp(1 << cnt, 0);
	vector <int> dp2(1 << cnt, 0);
	vector <int> good(1 << cnt, 0);
	dp[0] = 1;
	dp2[0] = 1;
	good[0] = true;
	for (int i = 1; i < (1 << cnt); ++i) {
		int lx = n, rx = -1;
		int total = 0;
		
		int S = 0;
		for (int j = 0; j < cnt; ++j) {
			if (i & (1 << j)) {
				dp[i] |= (dp[i ^ (1 << j)] && good[i ^ (1 << j)]) || dp2[i ^ (1 << j)];
				lx = min(lx, lt[j]);
				rx = max(rx, rt[j]);
				total += copies[j];
			
				S |= (1 << j);
				if (S != i) {
					dp2[i] |= (dp2[S] && dp2[i - S]);
				}
			}
		}

		int left_part = a * (rx - lx + 1);
		int right_part = b * total;

		if (left_part <= right_part) {
			good[i] = true;
		}
		dp2[i] |= (dp[i] && good[i]);
		//cout << bitset<4>(i) << " " << dp[i] << " " << dp2[i] << " " << good[i] << "\n";
	}

	vector <char> res;
	for (int i = 0; i < cnt; ++i) {
		int mask = (1 << cnt) - 1 - (1 << i);
		if ((dp[mask] && good[mask]) || dp2[mask]) {
			res.pb(tt[i]);
		}
	}

	cout << res.size() << " ";
	sort(all(res));
	for (char c : res) cout << c << " ";
}