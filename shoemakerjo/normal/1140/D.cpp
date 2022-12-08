#include <bits/stdc++.h>

using namespace std;

int n;

int dp[502][502];

int aft[502];
int bef[502];	

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int res = 0;
	for (int i = 2; i <= n-1; i++) {
		res += i*(i+1);
	}
	cout << res << endl;
}