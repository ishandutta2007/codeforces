#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#include<cstring>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define M 1000000007
#define N 211111
using namespace std;
typedef pair<int,int> pt;

int n;
int a[N], f[17][N];
int gg[N];
pair<int, long long> q[5000555], qq[5000555];

int ff(int x, int y) {
	int w = gg[y - x + 1];
	return __gcd(f[w][x], f[w][y - pw(w) + 1]);
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	cin >> n;
	for (int i =0 ; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) f[0][i] = a[i];
	for (int i = 1; i < 17; i++) 
		for (int j = 0; j < n; j++) if (j + pw(i) <= n) f[i][j] = __gcd(f[i - 1][j], f[i - 1][j + pw(i - 1)]);

	gg[1] = 0;
	for (int i = 2; i <= n; i++) gg[i] = gg[i / 2] + 1;
	
	int k = 0;
	for (int i = 0; i < n; i++) {
		int u = i;
		while (u < n) {
			int g = ff(i, u);
			int l = u;
			int r = n - 1;
			while (l < r) {
				int mid = (l + r + 1) / 2;
				if (ff(i, mid) == g) l = mid; else r = mid - 1;
			}
			q[k++] = mp(g, l - u + 1);
			u = l + 1;
		}
	}
	sort(q, q + k);
	int d = 0;
	for (int i = 0; i < k; i++) {
		if (d == 0 || q[i].F != qq[d - 1].F) {
			qq[d++] = q[i];
		} else qq[d - 1].S += q[i].S;
	}
	int z;
	cin >> z;
	while (z--) {
		int x;
		scanf("%d", &x);
		int t = upper_bound(qq, qq + d, mp(x, -1ll)) - qq;
		long long ans = 0;
		if (t == d || qq[t].F != x) ans = 0; else ans = qq[t].S;
		printf("%I64d\n", ans);

	}
	return 0;
}