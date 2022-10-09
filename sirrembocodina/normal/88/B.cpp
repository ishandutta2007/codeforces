#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <list>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <memory.h>
#include <cstdio>
#include <cstdlib>
        
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = n - 1; i >= 0 ; i--)
#define forv(i, a) for (int i = 0; i < (int)(a.size()); i++)
#define forab(i, a, b) for (int i = a; i < (int)(b); i++)
#define fordab(i, a, b) for (int i = b - 1; i >= (int)(a); i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define pi 3.1415926535897932
#define all(a) a.begin(), a.end()
#define eps 0.000000005

typedef long long int64;       
typedef long double ld;

vector<bool> b(26, false), c(27, false);
string s;
vector<string> a;

int main() {
//	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
	int n, m, d;
	cin >> n >> m >> d;
	a.resize(n);
	forn (i, n) {
		cin >> a[i];
	}
	forn (i, n) {
		forn (j, m) {
			if (a[i][j] == 'S') {
				c[26] = true;
			} else {
				c[int(a[i][j]) - int('a')] = true;
			}	
			forn (x, n) {
				forn (y, m) {
					if (a[x][y] != 'S' || a[i][j] == 'S' || d * d < (x - i) * (x - i) + (y - j) * (y - j)) {
						continue;
					}
					b[int(a[i][j]) - int('a')] = true;
				}
			}
		}
	}
	int ans = 0;
	cin >> s >> s;
	forv (i, s) {
		if (int(s[i]) > int('Z')) {
			if (!c[int(s[i]) - int('a')]) {
				cout << -1;
				return 0;
			}
			continue;
		}
		if (!c[26] || !c[int(s[i]) - int('A')]) {
			cout << -1;
			return 0;
		}
		ans += 1 - b[int(s[i]) - int('A')];
	}
	cout << ans;
}