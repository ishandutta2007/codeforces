#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <assert.h>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define forin(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define all(a) a.begin(), a.end()
#define fs first
#define sc second
#define elif else if
#define sqr(a) ((a) * (a))
#define mp make_pair
#define pb push_back
#define last(a) (*(a).end())
#define fill_zero(a) memset(a, 0, sizeof(a))
#define y1 botva
#define count botven
#define norm(a) a.erase(unique(all(a)), a.end());

typedef long double ld;
typedef long long ll;
typedef unsigned char uc;
typedef unsigned int ui;
typedef unsigned long long ull;

int a[1000000];

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	int n;
	cin >> n;
	forn (i, n) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	if (a[n - 1] == 1) {
		a[n - 1] = 2;
	} else {
		a[n - 1] = 1;
	}
	sort(a, a + n);
	forn (i, n) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}