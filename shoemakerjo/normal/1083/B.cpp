#include <bits/stdc++.h>

using namespace std;
#define maxn 500010
#define ll long long

int n;
ll k;
string a, b;
ll myval[maxn];
ll numfree[maxn]; //free reign for these

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k >> a >> b;


	int firstdiff = -1;
	ll res = 0LL;
	bool diff = false;
	for (int i = 0; i < n; i++) {
		if (diff) {
			numfree[i] = min(numfree[i-1] * 2LL, k);
			if (b[i] == 'b') {
				numfree[i] += 1LL;
			}
			if (a[i] == 'a') {
				numfree[i] += 1LL;
			}

			myval[i] = min(k , numfree[i] + 2LL);
		}
		else {
			if (a[i] == b[i]) {
				myval[i] = 1;
			}
			else {
				diff = true;
				myval[i] = 2;
			}
		}
	}

	for (int i = 0; i< n; i++) {
		// cout << i << " : " << myval[i] << endl;
		res += min(myval[i], k);
	}


	cout << res << endl;
}