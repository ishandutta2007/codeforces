#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;
typedef long double ld;

const long double pi = 3.1415926535897932384626433832795028841971l;

ll dx[4] = {-1, 0, 1, 0};
ll dy[4] = {0, -1, 0, 1};
ll DX[8] = {0, 1, 2, 1, 0, -1, -2, -1};
ll DY[8] = {2, 1, 0, -1, -2, -1, 0, 1};
ll nu[256];

int main() {
//	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
	nu['L'] = 0;
	nu['U'] = 1;
	nu['R'] = 2;
	nu['D'] = 3;
	ll n;
	cin >> n;
	string s;
	getline(cin, s);
	ll a[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	vector<pair<int, int> > v;
	forn (i, n) {
		getline(cin, s);
		vector<int> num(0);
		forn (i, s.size()) {
			num.pb(nu[s[i]]);
		}
		sort(num.begin(), num.end());
		num.pb(num[0]);
		forn (i, num.size() - 1) {
			int x = dx[num[i + 1]] - dx[num[i]];
			int y = dy[num[i + 1]] - dy[num[i]];
			forn (k, 8) {
				if (x == DX[k] && y == DY[k]) {
					a[k]++;
				}
			}
		}
	}
	ll P = a[0] + a[1] + a[2] + a[3] + a[4] + a[5] + a[6] + a[7];
	ll S = 0;
	ll x = 0, y = 0;
	forn (i, 8) {
		forn (j, a[i]) {
			ll x1 = x + DX[i];
			ll y1 = y + DY[i];
			S +=  (x1 * y - y1 * x) / 2;
			x = x1;
			y = y1;
		}
	}
	cout << (S + P) / 2 + 1;
        return 0;
}