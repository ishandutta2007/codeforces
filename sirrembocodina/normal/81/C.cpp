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
                   
vector<pair<int, int> > x;
vector<int> ans;

int main() {
	int a, b, n;
	cin >> n >> a >> b;
	x.resize(n);
	forn (i, n) {
		cin >> x[i].fs;
		if (a > b) {
			x[i].sc = i;
		} else {
			x[i].sc = -i;
		}
	}
	if (a == b) {
		forn (i, a) {
			cout << "1 ";
		}
		forn (i, a) {
			cout << "2 ";
		}
		return 0;
	}
	sort(x.begin(), x.end());
	ans.resize(n);
	if (a > b) {
		forn (i, a) {
			ans[x[i].sc] = 1;
		}
		forab (i, a, n) {
			ans[x[i].sc] = 2;
		}
	} else {
		forn (i, b) {
			ans[-x[i].sc] = 2;
		}
		forab (i, b, n) {
			ans[-x[i].sc] = 1;
		}
	}
	forv (i, ans) {
		cout << ans[i] << " ";
	}
}