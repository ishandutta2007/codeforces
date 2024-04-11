#include <bits/stdc++.h>

//http://codeforces.com/contest/761/problem/0

using namespace std;


typedef long long LL;
typedef pair<LL,LL> pp;


int main()
{
	int n, m;
	cin >> n >> m;
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<vector<int>> best(n, vector<int>(3));
	for (int i = 0; i < n; i++) {
		best[i][0] = best[i][1] = best[i][2] = 1000;
		for (int j = 0; j < m; j++) {
			int typ = islower(v[i][j]) ? 0 :
					isdigit(v[i][j]) ? 1 : 2;
			best[i][typ] = min(best[i][typ], min(j, m-j));
		}
	}
	int res = 1<<30;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			for (int k = j+1; k < n; k++) {
				vector<int> types = {0,1,2};
				do {
					res = min(res, best[i][types[0]]+best[j][types[1]]+best[k][types[2]]);
				}
				while (next_permutation(types.begin(), types.end()));
			}
		}
	}
	cout << res << endl;
	exit(0);
}