#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
#include <ctime>
#include <cmath>

using namespace std;

#define ll long long
#define clr(a) memset(a, 0, sizeof(a))
#define FOR(a, b) for (int a = 0; (a) < (b); ++a)
#define iter(a) typeof(a.begin())
#define foreach(it, a) for(typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define sqr(a) (a)*(a)
#define PI 2.0*acos(0.0)

const int INF = 1000000001;
const double EPS = 1e-8;

int a[5002];
int n;

int main()
{
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	cin >> n;
	FOR(i, n)
		cin >> a[i];
	sort(a, a + n);
	int ans = 0;
	FOR(i, n)
		if ((i != 0 && a[i] == a[i - 1])||(a[i] > n))
			ans++;
	cout << ans;
	return 0;
}