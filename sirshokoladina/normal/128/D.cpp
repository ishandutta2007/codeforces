#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define forn(i,n) for (int i = 0; i < (int)(n); i++)
#define ford(i,n) for (int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int a[1000000];

int main() {
	int n;
	cin >> n;
	forn (i, n) {
		scanf("%d", a + i); 
	}
	sort(a, a + n);
	forn (i, n - 1) {
		if (a[i + 1] > a[i] + 1) {
			cout << "NO";
			return 0;
		}
	}
	int l = 0, r = 0;
	for (int i = 0; i < n;) {
		if (i && l <= 0) {
			l += 2;
		}
		if (l > r) {
			cout << "NO";
			return 0;
		}
		int j;
		for (j = i; j < n && a[j] == a[i]; j++);
		int k = (j - i);
		int l0 = l, r0 = r;
		l = k - r0;
		r = k - l0;
		i = j;
	}
	if (l <= 0 && r >= 0) {
		cout << "YES";
	} else {
		cout << "NO";
	}
}