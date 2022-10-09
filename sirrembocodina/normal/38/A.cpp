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

vector<int> d;

int main() {
	int n;
	cin >> n;
	d.resize(n - 1);
	forn (i, n - 1) {
		cin >> d[i];
	}
	int a, b;
	cin >> a >> b;
	a--;
	b--;
	int ans = 0;
	for (int i = a; i < b; i++) {
		ans += d[i];
	}
	cout << ans;
}