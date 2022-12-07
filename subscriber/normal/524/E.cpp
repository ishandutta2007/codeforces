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
#define buli(x) __builtin_popcountll(x)
#define M 1000000007
#define N 411111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int n, m, k, q;
int x[N], y[N], a[N], b[N], aa[N], bb[N];
int ans[N];
int mi[2000222];

void init(int pos, int l, int r) {
	mi[pos] = -1;
	if (l == r) return;
	init(pos + pos, l, (l + r) / 2);
	init(pos + pos + 1, (l + r) / 2 + 1, r);
}

void mod(int pos, int l, int r, int x, int v) {
	if (x < l || x > r) return;
	if (l == r) {
		mi[pos] = v;
		return;
	}
	mod(pos + pos, l, (l + r) / 2, x, v);
	mod(pos + pos + 1, (l + r) / 2 + 1, r, x, v);

	mi[pos] = min(mi[pos + pos], mi[pos + pos + 1]);	
}

int fin(int pos, int l, int r, int ll, int rr) {
	ll = max(ll, l);
	rr = min(rr, r);
	if (ll > rr) return 1e9;
	if (l == ll && r == rr) return mi[pos];

	return min(fin(pos + pos, l, (l + r) / 2, ll, rr), 
	fin(pos + pos + 1, (l + r) / 2 + 1, r, ll, rr) );
}

void solve() {
	vector<pair<int, int> > ev;
	for (int i = 0; i < k; i++) {
		ev.pb(mp(y[i], -(i + 1)));
	}
	for (int i = 0; i < q; i++) {
		ev.pb(mp(bb[i], i + 1));
	}
	sort(ev.begin(), ev.end());
	init(1, 0, n - 1);
	for (int i = 0; i < ev.size(); i++) {
		int id = ev[i].S;
		if (id < 0) {
			id = (-id) - 1;
			mod(1, 0, n - 1, x[id], y[id]);			
		} else {
			id = id - 1;
			if (fin(1, 0, n - 1, a[id], aa[id]) >= b[id]) ans[id] = 1; 
		}
	}
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n >> m >> k >> q;
	for (int i = 0; i < k; i++) {
		scanf("%d%d", &x[i], &y[i]);
		x[i]--;
		y[i]--;
	}
	for (int i = 0; i < q; i++) {
		scanf("%d%d%d%d", &a[i], &b[i], &aa[i], &bb[i]);
		a[i]--;
		b[i]--;
		aa[i]--;
		bb[i]--;

		ans[i] = 0;
	}
	solve();
	for (int i = 0; i < k; i++) swap(x[i], y[i]);
	for (int i = 0; i < q; i++) {
		swap(a[i], b[i]);
		swap(aa[i], bb[i]);
	}
	swap(n, m);
	solve();

	for (int i = 0; i < q; i++) if (ans[i]) puts("YES"); else puts("NO");

	return 0;


}