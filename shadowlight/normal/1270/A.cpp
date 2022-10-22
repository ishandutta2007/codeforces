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
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, k1, k2;
		cin >> n >> k1 >> k2;
		bool exist = false;
		for (int j = 0; j < k1; j++) {
			int x;
			cin >> x;
			if (x == n) {
				exist = true;
			}
		}
		for (int j = 0; j < k2; j++) {
			int x;
			cin >> x;
		}
		cout << (exist ? "YES\n" : "NO\n");
	}
}