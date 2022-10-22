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
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	int m;
	cin >> m;
	vector <vector <int> > a(m, vector <int> (m, 0));
	int sh = 0;
	for (int n = m; n > 0; n -= 4) {
		int now = (n * n - 17);
		for (int j = 2; j < n - 2; j++) {
			a[sh][j + sh] = now--;
			a[sh + 1][j + sh] = now--;
			a[m - 1 - sh][j + sh] = now--;
			a[m - 2 - sh][j + sh] = now--;
			//
			a[j + sh][sh] = now--;
			a[j + sh][sh + 1] = now--;
			a[j + sh][m - 1 - sh] = now--;
			a[j + sh][m - 2 - sh] = now--;
		}
		now = n * n - 1;
		a[sh][sh] = now--;
		a[sh][sh + 1] = now--;
		a[sh + 1][sh] = now--;
		a[sh + 1][sh + 1] = now--;
		//
		a[m - 1 - sh][m - 1 - sh] = now--;
		a[m - 1 - sh][m - 2 - sh] = now--;
		a[m - 2 - sh][m - 1 - sh] = now--;
		a[m - 2 - sh][m - 2 - sh] = now--;
		//
		a[sh][m - 1 - sh] = now - 3;
		a[sh][m - 2 - sh] = now - 2;
		a[sh + 1][m - 1 - sh] = now - 1;
		a[sh + 1][m - 2 - sh] = now;
		now -= 4;
		//
		a[m - 1 - sh][sh] = now - 3;
		a[m - 1 - sh][sh + 1] = now - 2;
		a[m - 2 - sh][sh] = now - 1;
		a[m - 2 - sh][sh + 1] = now;

		sh += 2;
	}
	for (int i = 0; i < m; i++) {
		int sum = 0;
		for (int x : a[i]) {
			sum ^= x;
		}
		assert(!sum);
	}
	for (int j = 0; j < m; j++) {
		int sum = 0;
		for (int i = 0; i < m; i++) {
			sum ^= a[i][j];
		}
		assert(!sum);
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}