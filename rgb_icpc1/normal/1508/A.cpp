#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i ++)
using namespace std;
const int MN = 100005;
#define endl '\n'
typedef long long LL;
typedef pair<int, int> pii;
string s[3];
int a[3][2];

int main() {

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int Tc;
	for (cin >> Tc; Tc--; ) {
		int n;
		cin >> n;
		for (int i = 0; i < 3; i++) {
			cin >> s[i];
			a[i][0] = a[i][1] = 0;
			for (int j = 0; j < 2 * n;j++) a[i][s[i][j] - '0']++;
		
		}
		string e;
		bool flg = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = i + 1; j < 3; j++) {
				for (int k = 0; k < 2; k++) {
					if (a[i][k] >= n && a[j][k] >= n) {
						int ii = 0, jj = 0;
						while (ii != 2 * n || jj != 2 * n) {
							if (ii == 2 * n) e += s[j][jj++];
							else if (jj == 2 * n) e += s[i][ii++];
							else if (s[i][ii] == s[j][jj]) {
								e += s[i][ii];
								ii++;
								jj++;
							}
							else {
								if (s[i][ii] == '0' + k) e += s[j][jj++];
								else e += s[i][ii++];
							}
						}
						flg = 1;
						break;
					}
				}
				if (flg) break;
			}
			if (flg) break;
		}
		cout << e << endl;
	}

	return 0;

}