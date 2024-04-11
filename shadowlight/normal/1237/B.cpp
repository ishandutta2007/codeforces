#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int INF = 1e9 + 7;

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector <int> b(n);
	map <int, int> d;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		d[x] = i;
	}
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		b[i] = d[x];
	}
	int mn = INF;
	int cnt = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (b[i] > mn) {
			cnt++;
		}
		mn = min(mn, b[i]);
	}
	cout << cnt << "\n";
}