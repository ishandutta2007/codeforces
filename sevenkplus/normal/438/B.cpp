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

#define N 100010

int n, m, a[N], f[N], s[N];
int px[N],py[N],pz[N],p[N];

bool cmp(int x, int y) {
	return pz[x] > pz[y];
}

int fa(int x) {
	return f[x] == x ? x : (f[x] = fa(f[x])); 
}

int main () {
	cin >> n >> m;
	for (int i = 0; i < n; i ++) cin >> a[i];
	for (int i = 0; i < m; i ++) {
		cin >> px[i] >> py[i];
		px[i] --; py[i] --;
		pz[i] = min(a[px[i]],a[py[i]]);
	}
	for (int i = 0; i < m; i ++) p[i] = i;
	sort(p,p+m,cmp);
	for (int i = 0; i < n; i ++) {
		f[i] = i;
		s[i] = 1;
	}
	double S = 0;
	for (int _i = 0; _i < m; _i ++) {
		int i = p[_i];
		if (fa(px[i]) != fa(py[i])) {
			int c = s[fa(px[i])];
			int d = s[fa(py[i])];
			S += pz[i]*(double)c*(double)d*2;
			//cout << pz[i] << " " << c << " " << d << endl;
			s[fa(px[i])] = 0;
			f[fa(px[i])] = fa(py[i]);
			s[fa(py[i])] += c;
		}
	}
	printf ("%.9lf\n", S/n/(n-1));
	return 0; 
}