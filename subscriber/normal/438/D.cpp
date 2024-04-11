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

int n, m;
int old[N];
pt ma[888888];
long long s[N];

void mo(int pos, int l, int r, int x, int v) {
	if (x < l || x > r) return;
	if (l == r) {
		ma[pos] = mp(v, x);
		return;
	}
	mo(pos + pos, l, (l + r) / 2, x, v);
	mo(pos + pos + 1, (l + r) / 2 + 1, r, x, v);
	ma[pos] = max(ma[pos + pos], ma[pos + pos + 1]);	
}

pt fm(int pos, int l, int r, int ll, int rr) {
	ll = max(ll, l);
	rr = min(rr, r);
	if (ll > rr) return mp(-1, -1);
	if (l == ll && r == rr) {
		return ma[pos];
	}
	return max( fm(pos + pos, l, (l + r) / 2, ll, rr), fm(pos + pos + 1, (l + r) / 2 + 1, r, ll, rr));
}

void add(int x, int v) {
	x++;
	while (x <= n) {
		s[x] += v;
		x = x + x - (x & (x - 1));
	}
}

long long fin(int x) {
	long long r = 0;
	while (x > 0) {
		r += s[x];
		x &= x - 1;
	}
	return r;
}

void change(int x, int y) {
	add(x, -old[x]);
	old[x] = y;
	add(x, y);
	mo(1, 0, n - 1, x, y);
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		change(i, x);
	}
	for (int i = 0; i < m; i++) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int x, y;
			scanf("%d%d", &x, &y);
			printf("%I64d\n", fin(y) - fin(x - 1));
		} else if (t == 2) {
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			x--;
			y--;
			for(;;) {
				pt e = fm(1, 0, n - 1, x, y);
				if (e.F < z) break;
				change(e.S, e.F % z);
			}
		} else if (t == 3) {
			int x, y;
			scanf("%d%d", &x, &y);
			change(x - 1, y);
		}
	}
	return 0;
}