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

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = n - 1 ; i >= 0 ; i--)
#define forv(i, a) for (int i = 0; i < (int)(a.size()); i++)
#define forab(i, a, b) for (int i = a; i < (int)(b); i++)
#define fordab(i, a, b) for (int i = b - 1; i >= (int)(a); i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define int64 long long       
#define ld long double
#define pi 3.1415926535897932
#define all(a) a.begin(), a.end()

vector<int> g[3];
int d[3];
bool used[3];
string ans = "";

int main() {
	int n = 3;
	forn (i, n) {
		d[i] = 0;
		used[i] = false;
	}
	forn (i, n) {
		char a, b, c;
		string s;
		cin >> s;
		a = s[0];
		b = s[1];
		c = s[2];
		if (b == '>') {
			swap(a, c);
		}
		int x = a - 'A', y = c - 'A';
		d[y]++;
		g[x].pb(y);
	}
	forn (i, n) {
		bool ok = false;
		forn (j, 3) {
			if (!d[j] && !used[j]) {
				ok = true;
				ans += 'A' + j;
				used[j] = true;
				forv (k, g[j]) {
					d[g[j][k]]--;
				}
				break;
			}
		}
		if (!ok) {
			cout << "Impossible";
			return 0;
		}
	}
	cout << ans;
}