#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const ll INF = 1e16;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector <vector <ll> > a(n, vector <ll> (n, 0));

	ll now = 1;

	for (int i = 1; i < n; ++i) {
		int y = i;
		int x = 0;
		bool turn = false;
		while (y >= 0) {
			a[x++][y--] = (turn ? now : 0);
			turn ^= 1;
		}
		now *= 2;
	}	
	for (int i = 1; i < n - 1; ++i) {
		int x = i, y = n - 1;
		bool turn = false;
		while (x < n) {
			a[x++][y--] = (turn ? now : 0);
			turn ^= 1;
		}
		now *= 2;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			assert(a[i][j] < INF);
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	int q;
	cin >> q;

	for (int i = 0; i < q; ++i) {
		ll sum;
		cin >> sum;
		int x = 0, y = 0;
		while (x < n - 1 || y < n - 1) {
			cout << x + 1 << " " << y + 1 << endl;
			if (x == n - 1) {
				++y;
			} else if (y == n - 1) {
				++x;
			} else {
				ll down = a[x + 1][y], left = a[x][y + 1]; 
				if (down) {
					if (sum & down) {
						++x;
					} else {
						++y;
					}
				} else {
					if (sum & left) {
						++y;
					} else {
						++x;
					}
				}
			}
		}
		cout << n << " " << n << endl;
	}

}