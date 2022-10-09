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
	int n, x, ans;
	cin >> n >> x;
	ans = x;
	a.resize(n);
	forn (i, n) {
		cin >> a[i];
	}
	forn (i, n) {
		for (int j = i; j < n; j++) {
			ans = max(ans, (x / a[i]) * a[j] + (x % a[i]));
		}
	}
	cout << ans;
}