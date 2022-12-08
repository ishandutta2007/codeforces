#include <bits/stdc++.h>

using namespace std;
#define maxn 100010

int n, k;
int nums[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	//longest segment such that no two cons are samae colors
	int clen = 0;

	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (nums[i] == nums[i-1]) {
			clen = 1;
		}
		else clen++;

		ans = max(ans, clen);
	}

	cout << ans << endl;

}