#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <cassert>
#include <set>
#include <algorithm>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; --i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sqr(a) ((a) * (a))
#define all(a) a.begin(), a.end()

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;

const ld pi = 3.1415926535897932384626433832795l;

int a[1000000];
int nx[2000010];

int main () {
#ifndef SUKPZDC
	//freopen(".in", "rt", stdin);
	//freopen(".out", "wt", stdout);
#else
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif
	int n, m;
	cin >> n >> m;
	forn (i, n) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	{
		int j = 0;
		forn (i, 2000010) {
			while (j < n && i > a[j]) {
				j++;
			}
			nx[i] = j;
		}
	}
	int mx = 0;
	for (int i = 1; i <= a[0]; ++i) {
		int j = 0;
		int k = 0;
		bool ok = 1;
		while (j < n) {
			k += i;
			int j1 = nx[k];
			if (j1 != j) {
				if (a[j1 - 1] - (k - i) > m) {
					ok = 0;
					break;
				}
				j = j1;
			}
		}
		if (ok) {
			mx = i;
		}
	}
	cout << mx << endl;
	return 0;
}