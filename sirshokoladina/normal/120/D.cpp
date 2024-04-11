#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <map>
#include <set>
#include <deque>
#include <queue>

using namespace std;

#define forn(i,n) for (int i = 0; i < (int)(n); i++)
#define ford(i,n) for (int i = (int)(n) - 1; i >= 0; i--)

int a[100][100];
int s[100];

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int n, m;
	cin >> n >> m;
	int l = 0;
	forn (i, n) {
		forn (j, m) {
			cin >> a[i][j];
			l += a[i][j];
		}
	}
	vector<int> A(3);
	cin >> A[0] >> A[1] >> A[2];
	if (l != A[0] + A[1] + A[2]) {
		cout << 0;
		return 0;
	}
	sort(A.begin(), A.end());
	vector<vector<int> > b(1, A);
	while (next_permutation(A.begin(), A.end())) {
		b.push_back(A);
	}
	int ans = 0;
	forn (i, 2) {
		if (n >= 3) {
			forn (j, n) {
				int t = 0;
				forn (k, m) {
					t += a[j][k];
				}
				if (j == 0) {
					s[j] = 0;
				}
				s[j + 1] = s[j] + t;
			}
			forn (j, b.size()) {
				for (int k = 1; k < n; k++) {
					if (s[k] == b[j][0] + b[j][1]) {
						for (int l = 1; l < k; l++) {
							if (s[l] == b[j][0]) {
								ans++;
							}
						}
					}
				}
			}
		}
		forn (j, 100) {
			forn (k, j) {
				swap(a[k][j], a[j][k]);
			}
		}
		swap(n, m);
	}
	cout << ans;
}