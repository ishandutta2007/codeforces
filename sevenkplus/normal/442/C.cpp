#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <bitset>
#include <numeric>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define N 500010
int a[N],sn,n;

int main()
{
	cin >> n;
	ll S = 0;
	while (n--) {
		int x; cin >> x;
		while (sn >= 2 && a[sn] <= a[sn-1] && a[sn] <= x) {
			S += min(a[sn-1],x);
			sn --;
		}
		a[++sn] = x;
	}
	a[sn+1] = 0;
	int p = max_element(a+1,a+sn+1)-a;
	if (p == sn) {reverse(a+1,a+sn+1); p = 1;}
	if (p == 1) {
		for (int i = 3; i <= sn; i ++) S += a[i];
		cout << S << endl;
		return 0;
	}
	int rm = sn;
	int l = p, r = p+1;
	while (rm >= 3) {
		if (min(a[l-1],a[l+1]) <= min(a[r-1],a[r+1])) {
			S += min(a[r-1],a[r+1]); r ++;
		} else {
			S += min(a[l-1],a[l+1]); l --;
		}
		rm --;
	}
	cout << S << endl;
	return 0;
}