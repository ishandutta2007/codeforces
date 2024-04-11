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

typedef pair<ll,int> PLI;
typedef pair<ll,ll> PLL;

#define N 100010
int n,w, p[N],c[N];
int a[N],b[N],ib[N];
ll rp[N];

bool cmp(int x, int y) {return c[x] < c[y];}
bool cmpb(int x, int y) {return p[x] < p[y];}

#define L 300
bool v[N];

ll crs(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	return (x2-x1)*(y3-y1)-(y2-y1)*(x3-x1);
}

struct T {
	int st[L], sn;
	ll ad;
	int ws,wt;
	
	T () {sn = 0;} 
	
	void rec(int bx) {
		for (int i = ws; i <= bx; i ++) 
			rp[i] += 1;
		sn = 0;
		for (int i = ws; i < wt; i ++) if (v[i]) {
			while (sn >= 2 && crs(p[b[st[sn-2]]],p[b[st[sn-2]]]*rp[st[sn-2]],p[b[st[sn-1]]],p[b[st[sn-1]]]*rp[st[sn-1]],p[b[i]],p[b[i]]*rp[i]) >= 0) sn --;
			st[sn++] = i;
		}
		la = 0;
	}
	
	int la;
	
	ll ans(int x) {
		return p[b[x]]*ad+p[b[x]]*rp[x];
	}
	
	PLI ask() {
		if (sn == 0) return mp(-1,-1);
		while (la < sn-1 && ans(st[la+1]) > ans(st[la])) la ++;
		return mp(ans(st[la]),p[b[st[la]]]);
	}
}A[N/L+1];

void upd(int x) {
	int bx = ib[x];
	v[bx] = 1;
	A[bx/L].rec(bx);
	for (int i = 0; i < bx/L; i ++) 
		A[i].ad += 1;
}

void ask(ll Sc) {
	PLI S = mp(0,0);
	for (int i = 0; i < (n-1)/L+1; i ++) 
		S = max(S,A[i].ask());
	printf ("%I64d %d\n",S.fi+Sc,S.se);
}

int main()
{
	cin >> n >> w;
	for (int i = 0; i < n; i ++) {
		cin >> p[i] >> c[i];
		a[i] = b[i] = i;
	}
	for (int i = 0; i < (n-1)/L+1; i ++) {
		A[i].ws = i*L; A[i].wt = min((i+1)*L,n);
	}
	sort(a,a+n,cmp);
	sort(b,b+n,cmpb);
	for (int i = 0; i < n; i ++) ib[b[i]] = i;
	for (int i = 0, j = 0; i <= c[a[n-1]]+1; i ++) {
		while (j < n && c[a[j]] < i) {
			upd(a[j]);
			j ++;
		}
		ll Sc = 0;
		if (j < n) Sc = (ll)i*(n-j)*w;
		ask(Sc);
	}
	return 0;
}