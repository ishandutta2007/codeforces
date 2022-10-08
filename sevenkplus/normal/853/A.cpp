#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pct __builtin_popcount

#define rep(i,l,r) for (int i=(l); i<=(r); i++)
#define repd(i,r,l) for (int i=(r); i>=(l); i--)
#define rept(i,c) for (__typeof((c).begin()) i=((c).begin()); i!=((c).end()); i++)

#define N 300010
int n, k;
int a[N], p[N], b[N], c[N];
bool v[N];

bool cmp(int x, int y) {
	return a[x] < a[y];
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i ++)
		scanf("%d", a+i);
	for (int i = 0; i < n; i ++) p[i] = i;
	sort(p, p+n, cmp);
	int nw = 0;
	ll S = 0;
	for (int i = n-1; i >= 0; i--)
		if (i+k < n && !v[i+k]) {
			v[i+k] = true;
			c[i+k] = i+k;
			//b[i] = i+k;
		} else {
			while (v[p[nw]]) nw ++;
			v[p[nw]] = true;
			//b[i] = p[nw];
			c[p[nw]] = i+k;
			S += (ll)a[p[nw]]*(i+k-p[nw]);
		}
	cout << S << endl;
	for (int i = 0; i < n; i ++)
		printf ("%d%c", c[i]+1, i == n-1?'\n':' ');
	return 0;
}