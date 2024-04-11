#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <deque>
#include <map>

using namespace std;

#define forn(i,n) for (int i = 0; i < (int)(n); i++)
#define ford(i,n) for (int i = (int)(n) - 1; i >= 0; i--)
#define mp make_pair
#define pb push_back
#define fs first
#define sc second

int b[10000];

int main () {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	forn (i, n)
		b[i] = 0;
	int s = 0;
	b[0] = 1; 
	forn (i, 10 * n + 10) {
		s += i;
		s %= n;
		b[s] = 1;
	}
	forn (i, n)
		if (!b[i]) {
			cout << "NO";
			return 0;
		}
	cout << "YES";
	return 0;
}