#include <bits/stdc++.h>

using namespace std;
#define int long long

int n, m, k;
const int MAXN = 1e6 + 10;
int arr[MAXN], pref[MAXN];


void read() {
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++) { 
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr, arr + n);
	int q;
	cin >> q;
	while (q--) {
		int a; cin >> a;
		a = n - a;
		cout << sum - arr[a] << endl;
	}
}

void run() {
	
}

void write() {
	
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}