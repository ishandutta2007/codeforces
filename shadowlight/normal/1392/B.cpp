#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;



void get(vector <int>& a) {
	int d = a[0];
	int n = a.size();
	for (int i = 0; i < n; ++i) {
		d = max(d, a[i]);
	}
	for (int i = 0; i < n; ++i) {
		a[i] = d - a[i];
	}
}\

void print(vector<int>&a) {
	for (int x : a) {
		cout << x << " ";
	}
	cout << "\n";
}

void solve() {
	int n;
	ll k;
	cin >> n >> k;
	vector <int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	get(a);
	--k;
	if (!k) {
		print(a);
		return;
	}
	k %= 2;
	if (k) {
		get(a);
	}
	print(a);
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}

}