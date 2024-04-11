#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define forn(i,n) for (long long i = 0; i < (int)(n); i++)
#define ford(i,n) for (long long i = (long long)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

long long a[1010][1010];
long long s[1010][1010];
long long t[1010][1010];

long long mod = 1000000007;

int main() {
	long long n, m, k;
	cin >> n >> m >> k;
	long long ans[2];
	forn (r, 2) {
		forn (i, 1010) {
			forn (j, 1010) {
				a[i][j] = s[i][j] = t[i][j] = 0;
			}
		}
		forn (i, 1010) {
			ford (j, n + 1) {
				if (j == n || i == 0) {
					a[i][j] = (i == 0 && j == n);
				} else {
					a[i][j] = t[i - 1][j + 2];
				}
			}
			s[i][n + 1] = t[i][n + 1] = 0;
			ford (j, n + 1) {
				s[i][j] = (s[i][j + 1] + a[i][j]) % mod;
				t[i][j] = (t[i][j + 1] + s[i][j]) % mod;
			}
		}
		ans[r] = s[k][1];
		swap(n, m);
	}
	cout << ans[0] * ans[1] % mod;
}