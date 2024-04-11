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
#define M 1000000009
#define N 2000111
using namespace std;
typedef pair<int,int> pt;

int n, m;
int sum[N], add1[N], add2[N];
int g[N][2], ac[N][2], f[N];
int a[N];

void init(int pos, int l, int r) {
	if (l == r) {
		sum[pos] = a[l];
		add1[pos] = add2[pos] = 0;
		return;
	}
	init(pos + pos, l, (l + r) / 2);
	init(pos + pos + 1, (l + r) / 2 + 1, r);
	sum[pos] = (sum[pos + pos] + sum[pos + pos + 1]) % M;
}

void mod(int pos, int l, int r, int ll, int rr, int v1, int v2) {
	ll = max(ll, l);
	rr = min(rr, r);
	if (ll > rr) return;
	int len = r - l + 1;
	if (ll == l && rr == r) {
		add1[pos] = (add1[pos] + v1) % M;
		add2[pos] = (add2[pos] + v2) % M;
		sum[pos] = (sum[pos] + ac[len][0] * 1ll * v1 + ac[len][1] * 1ll * v2) % M;
		return;
	}
	int mid = (l + r) / 2;
	if (add1[pos] != 0 || add2[pos] != 0) {
		mod(pos + pos, l, mid, l, r, add1[pos], add2[pos]);
		int po = mid - l + 1;

		int vv1 = (g[po][0] * 1ll * add1[pos] + g[po][1] * 1ll * add2[pos]) % M;
		int vv2 = (g[po + 1][0] * 1ll * add1[pos] + g[po + 1][1] * 1ll * add2[pos]) % M;
		mod(pos + pos + 1, mid + 1, r, l, r, vv1, vv2);
		add1[pos] = add2[pos] = 0;
	}
	mod(pos + pos, l, mid, ll, rr, v1, v2);
	if (mid + 1 > ll) {
		int po = mid + 1 - ll;
		int vv1 = (g[po][0] * 1ll * v1 + g[po][1] * 1ll * v2) % M;
		int vv2 = (g[po + 1][0] * 1ll * v1 + g[po + 1][1] * 1ll * v2) % M;
		mod(pos + pos + 1, mid + 1, r, ll, rr, vv1, vv2);		
	} else {
		mod(pos + pos + 1, mid + 1, r, ll, rr, v1, v2);
	}		
	sum[pos] = (sum[pos + pos] + sum[pos + pos + 1]) % M;
}

int fin(int pos, int l, int r, int ll, int rr) {
	ll = max(ll, l);
	rr = min(rr, r);
	if (ll > rr) return 0;
	if (ll == l && rr == r) return sum[pos];
	int mid = (l + r) / 2;
	if (add1[pos] != 0 || add2[pos] != 0) {
		mod(pos + pos, l, mid, l, r, add1[pos], add2[pos]);
		int po = mid - l + 1;

		int vv1 = (g[po][0] * 1ll * add1[pos] + g[po][1] * 1ll * add2[pos]) % M;
		int vv2 = (g[po + 1][0] * 1ll * add1[pos] + g[po + 1][1] * 1ll * add2[pos]) % M;
		mod(pos + pos + 1, mid + 1, r, l, r, vv1, vv2);
		add1[pos] = add2[pos] = 0;
	}

	int q1 = fin(pos + pos, l, mid, ll, rr);
	int q2 = fin(pos + pos + 1, mid + 1, r, ll, rr);
	return (q1 + q2) % M;
}



int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	cin >> n >> m;

	g[0][0] = 1;
	g[1][1] = 1;
	for (int i = 2; i <= n + 3; i++) {
		for (int j = 0; j < 2; j++)
			g[i][j] = (g[i - 1][j] + g[i - 2][j]) % M;
	}
	for (int i = 0; i < n; i++) for (int j = 0; j < 2; j++) ac[i + 1][j] = (ac[i][j] + g[i][j]) % M;

	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	init(1, 0, n - 1);

	while (m--) {
		int type, x, y;
		scanf("%d%d%d", &type, &x, &y);
		x--;
		y--;
		if (type == 1) {
			mod(1, 0, n - 1, x , y, 1, 1);
		} else {
			printf("%d\n", fin(1, 0, n - 1, x, y));
		}
	}

	return 0;
}