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

#define N 200010
int n, q;
int a[N], px1[N], px2[N], py1[N], py2[N];
int sy[N]; // # with y < i
ll S[N];

ll C(int x) { return (ll)x*(x-1)/2; }

int f[N];
vector<int> c[N];

void upd(int x) {
	x++;
	while (x <= n) {
		f[x] ++;
		x += (x&-x);
	}
}

int ask(int x) {
	// < x
	//x++;
	int S = 0;
	while (x) {
		S += f[x];
		x -= (x&-x);
	}
	return S;
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i ++) {
		scanf("%d", a+i);
		a[i] --;
		sy[a[i]+1]++;
	}
	for (int i = 0; i < q; i ++) {
		scanf("%d%d%d%d", px1+i, py1+i, px2+i, py2+i);
		px1[i] --;
		px2[i] --;
		py1[i] --;
		py2[i] --;
	}
	for (int i = 0; i < n; i ++)
		sy[i+1] += sy[i];
	
	for (int i = 0; i < q; i ++) {
		S[i] += C(n);
		S[i] -= C(px1[i]);
		S[i] -= C(n-px2[i]-1);
		S[i] -= C(sy[py1[i]]);
		S[i] -= C(n-sy[py2[i]+1]);
	}
	
	for (int i = 0; i < q; i ++) {
		c[px1[i]].pb(i);
		c[px2[i]+1].pb(i);
	}
	
	for (int i = 0; i <= n; i ++) {
		rept(j, c[i]) {
			if (px1[*j] == i) {
				S[*j] += C(ask(py1[*j]));
				S[*j] += C(i-ask(py2[*j]+1));
			}
			if (px2[*j]+1 == i) {
				S[*j] += C(sy[py1[*j]]-ask(py1[*j]));
				S[*j] += C(n-i-(sy[py2[*j]+1]-ask(py2[*j]+1)));
			}
		}
		if (i == n) break;
		upd(a[i]);
	}
	
	for (int i = 0; i < q; i ++)
		cout << S[i] << endl;
	return 0;
}