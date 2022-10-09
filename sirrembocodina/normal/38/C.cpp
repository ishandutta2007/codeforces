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
	int n, l;
	cin >> n >> l;
	a.resize(n);
	forn (i, n) {
		cin >> a[i];
	}
	int ans = 0;
	for (int d = l; d <= 100; d++) {
		int cur = 0;
		forn (i, n) {
			if (a[i] < d) {
				continue;
			}
			cur += d * (a[i] / d);
		}
		ans = max(ans, cur);
	}
	cout << ans;
}