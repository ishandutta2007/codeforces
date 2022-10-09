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
        
int main() {
	int n;
	cin >> n;
	for (int i = 1; i * (i + 1) <= 2 * n; i++) {
		if (i * (i + 1) == 2 * n) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}