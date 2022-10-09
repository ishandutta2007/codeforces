#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <memory.h>
#include <cstdio>
#include <cstdlib>
        
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = n - 1 ; i >= 0 ; i--)
#define forv(i, a) for (int i = 0; i < (int)(a.size()); i++)
#define forab(i, a, b) for (int i = a; i < (int)(b); i++)
#define fordab(i, a, b) for (int i = b - 1; i >= (int)(a); i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define pi 3.1415926535897932
#define all(a) a.begin(), a.end()
#define sqr(x) ((x) * (x))

typedef long long int64;       
typedef long double ld;
                   
vector<vector<int> > g;

int f(string s) {
	switch (s[0]) {
		case 'A': return 0;
		case 'C': return (s[1] == 'h' ? 1 : 2);
		case 'T': return 3;
		case 'D': return 4;
		case 'S': return 5;
		case 'H': return 6;
	}
}

int main() {
//	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
	int n, a, b, c;
	cin >> n;
	g.resize(7);
	forn (i, n) {
		string a, b;
		cin >> a >> b >> b;
		cerr << f(a) << " " << f(b) << endl;
		g[f(a)].pb(f(b));
	}
	cin >> a >> b >> c;
	//  ,   !
	int i[7];
	pair<int, int> ans = mp(2100000000, 0);
	for (i[0] = 0; i[0] < 3; i[0]++) {
		for (i[1] = 0; i[1] < 3; i[1]++) {
			for (i[2] = 0; i[2] < 3; i[2]++) {
				for (i[3] = 0; i[3] < 3; i[3]++) {
					for (i[4] = 0; i[4] < 3; i[4]++) {
						for (i[5] = 0; i[5] < 3; i[5]++) {
							for (i[6] = 0; i[6] < 3; i[6]++) {
								int x, y, z, m;
								x = y = z = m = 0;
								forn (i1, 7) {
									if (i[i1] == 0) {
										x++;
									} else if (i[i1] == 1) {
										y++;
									} else {
										z++;
									}
									forv (j, g[i1]) {
										if (i[i1] == i[g[i1][j]]) {
											m++;
										}
									}
								}
								if (!x || !y || !z) {
									continue;
								}
								x = a / x;
								y = b / y;
								z = c / z;
								ans = min(ans, mp(max(abs(x - y), max(abs(x - z), abs(y - z))), -m));
							}
						}
					}
				}
			}
		}
	}
	cout << ans.fs << " " << -ans.sc;

}