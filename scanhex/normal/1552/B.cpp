#include <bits/stdc++.h>

using namespace std;
using nagai = long long;

const int N = 50000;
int rofl[N][5];

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for(int i = 0;i < n; ++i)
			for (int j = 0;j  < 5; ++j)
				cin >> rofl[i][j];
		int res = 0;
		for(int i = 1; i < n; ++i)  {
			int c = 0; 
			for (int j = 0; j < 5;++j) 
				c += rofl[i][j] < rofl[res][j];
			if (c >= 3) 
				res = i;
		}
		bool bad = false;
		for(int i = 0; i < n; ++i)  {
			int c = 0; 
			for (int j = 0; j < 5;++j) 
				c += rofl[i][j] < rofl[res][j];
			if (c >= 3) 
				bad = true;
		}
		if (bad) res = -2;
		cout << res + 1 << '\n';
	}
  return 0;
}