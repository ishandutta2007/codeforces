#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

#define forab(i, a, b) for (int i = a; i < (int)(b); i++)
#define fordab(i, a, b) for (int i = b - 1; i >= (int)(a); i--)
#define forn(i, n) forab (i, 0, n)
#define ford(i, n) fordab (i, 0, n)
#define forv(i, a) forn (i, a.size())
#define mp make_pair
#define fs first
#define sc second
#define pb push_back

typedef long long int64;

const int64 mod = 1000000007;

int a[5];

int main() {
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
	int n;
	cin >> n;
	forn (i, n) {
		int x;
		cin >> x;
		a[x]++;
	}
	int ans = a[4];
	ans += a[3];
	a[1] = max(a[1] - a[3], 0);
	ans += (a[1] + a[2] + a[2]) / 4 + bool((a[1] + a[2] + a[2]) % 4);
	cout << ans;
}