#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define maxn 200010

int n;
ll a[maxn];
ll b[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n/2; i++) {
		cin >> b[i];
	}
	int ot;

	for (int i = 1; i <= n/2; i++) {
		ot = n-i+1;
		if (i == 1) {
			a[i] = 0LL;
			a[ot] = b[i];
			continue;
		}
		a[i] = a[i-1];

		a[ot] = b[i] - a[i];

		if (a[ot] > a[ot+1]) {
			a[ot] = a[ot+1];
			a[i] = b[i] - a[ot];
		}

	}


	for (int i = 1; i <= n; i++) {
		cout << a[i] << " " ;
	}
	cout << endl;

}