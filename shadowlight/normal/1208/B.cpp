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
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector <int> a(n);
	map <int, bool> exist;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int l = n - 1;
	for (; l >= 0; l--) {
		if (exist[a[l]]) break;
		exist[a[l]] = true;
	}
	l++;
	int res = l;
	int now = l;
	map <int, bool> ex;
	for (int i = 0; i < n; i++) {
		now--;
		if (ex[a[i]]) break;
		ex[a[i]] = true;
		while (l < n && exist[a[i]]) {
			exist[a[l]] = false;
			now++;
			l++;
		}
		res = min(res, now);
	}
	cout << res << "\n";
}