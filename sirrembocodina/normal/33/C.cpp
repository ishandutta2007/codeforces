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

vector<int> a, d;

int main() {
//	freopen("intput.txt","rt",stdin);
//	freopen("output.txt","wt",stdout);
	int n;
	cin >> n;
	a.resize(n);
	d.resize(n);
	forn (i, n) {
		cin >> a[i];
	}
	d[0] = max(-2 * a[0], 0);
	int sum = 0;
	forn (i, n) {
		sum += a[i];
		if (i == 0) {
			continue;
		}
		d[i] = max(d[i - 1], -2 * sum);
	}
	int ans = 0;
	sum = 0;
	for (int i = n - 1; i > 0; i--) {
		sum += a[i];
		ans = max(-2 * sum + d[i - 1], ans);
	}
	sum += a[0];
	ans = max(ans, -2 * sum);
	ans = max(ans, d[n - 1]);
	cout << sum + ans;
}