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
              
int b[1000];
        
int main() {
	int n;
	cin >> n;
	forn (i, n) {
		int a;
		cin >> a;
		b[a - 1]++;
	}
	int mx = 0, ans = 0;
	forn (i, 1000) {
		ans += bool(b[i]);
		mx = max(mx, b[i]);
	}
	cout << mx << " " << ans;
}