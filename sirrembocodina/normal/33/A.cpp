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
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define int64 long long       
#define ld long double
#define pi 3.1415926535897932
#define all(a) a.begin(), a.end()

vector<int> a;

int main() {
//	freopen("intput.txt","rt",stdin);
//	freopen("output.txt","wt",stdout);
	int n, m, k;
	cin >> n >> m >> k;
	a.assign(m, 100000000);
	forn (i, n) {
		int r, c;
		cin >> r >> c;
		a[r - 1] = min(a[r - 1], c);
	}
	int ans = 0;
	forn (i, m) {
		ans += a[i];
	}
	cout << min(ans, k);
}