#include <bits/stdc++.h>

using namespace std;

int n;

map<int, int> oc;
map<int, int> ec;

long long ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	int cpref = 0;
	ec[cpref]++;
	int cur =  0;
	for (int i = 1; i <= n; i++) {
		cin >> cpref;
		cur = cur ^ cpref;
		if (i%2 == 0) {
			ans = ans + ec[cur];
			ec[cur]++;
		}
		else {
			ans = ans + oc[cur];
			oc[cur]++;
		}
	}
	cout << ans << endl;
}