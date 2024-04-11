#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

struct Res {
	int a, b, c;
};

const int N = 1097;

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	vector <Res> dp(N, {-1, -1, -1});
	dp[0] = {0, 0, 0};

	for (int i = 0; i < N - 7; ++i) {
		if (dp[i].a == -1) continue;
		++dp[i].a;
		dp[i + 3] = dp[i];
		--dp[i].a;

		++dp[i].b;
		dp[i + 5] = dp[i];
		--dp[i].b;

		++dp[i].c;
		dp[i + 7] = dp[i];
		--dp[i].c;
	}

	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;
		if (dp[n].a == -1) {
			cout << "-1\n";
		} else {
			cout << dp[n].a << " " << dp[n].b << " " << dp[n].c << "\n";
		}
	}

}