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
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector <ll> a(n), b(n);
	
	map <ll, int> cnt;

	ll res = 0;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	vector <bool> used(n, false);
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		if (cnt[a[i]] >= 2) {
			for (int j = 0; j < n; j++) {
				if ((a[i] | a[j]) == a[i]) {
					used[j] = true;
				}
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (used[i]) res += b[i];
	}
	cout << res << "\n";

}