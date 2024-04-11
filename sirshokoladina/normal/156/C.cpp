#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <utility>
#include <cstdlib>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <memory.h>
#include <ctime>
#include <cctype>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define mp make_pair
#define fs first
#define sc second
#define pb push_back

typedef long double ld;
typedef long long ll;
typedef unsigned char uc;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ld PI = 3.141592653589793238462643l;

const int mod = 1000000007;

int d[102][3000];

int main() {
	//freopen("input.txt", "rt", stdin)
	//freopen("output.txt", "wt", stdout)
	forn (i, 102) {
		forn (j, 3000) {
			if (i == 0) {
				d[i][j] = (j == 0);
				continue;
			}
			d[i][j] = 0;
			forn (k, 26) {
				if (k > j) {
					break;
				}
				d[i][j] += d[i - 1][j - k];
				if (d[i][j] >= mod) {
					d[i][j] -= mod;
				}
			}
		}
	}
	int t;
	cin >> t;
	string s;
	getline(cin, s);
	forn (qwe, t) {
		getline(cin, s);
		int k = 0;
		forn (i, s.size()) {
			k += s[i] - 'a';
		}
		cout << (d[s.size()][k] + mod - 1) % mod << endl;
	}
	return 0;
}