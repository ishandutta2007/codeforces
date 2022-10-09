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

int main() {
//	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
	int n;
	cin >> n;
	vector<int> a(n);
	forn (i, n) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	forn (i, n - 1) {
		if (a[i] != 1 && a[i + 1] < 2 * a[i] && a[i] != a[i + 1]) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}