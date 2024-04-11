#include<stdio.h>
#include<iostream>
#include<vector>
#include<bitset>
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
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define M 1000000007
#define N 2000222

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

unsigned int ed[2016][85];
unsigned int need[85];


int n, m[2];

int x[2][N], y[2][N];

int NOT(int x) {
	return x < n ? x + n : x - n;
}

void ae(int a, int b) {
	ed[a][(b >> 5)] |= pw(b & 31);
//	ed[b][(a >> 5)] |= pw(a & 31);
}

int getv(int x) {
	if (x > 0) return x - 1; 
	return -x - 1 + n;
}


int q[2016], q1, q2;

int d[2016][2016];

void findd() {
	int sz = (n + n + 32) / 32;

	for (int i = 0; i < n + n; i++) {
		for (int j = 0; j < sz; j++) need[j] = 0;
		
		for (int j = 0; j < n + n; j++) if (j != i) need[j >> 5] |= pw(j & 31);
		q1 = q2 = 0;

		q[q1++] = i;
		while (q1 != q2) {
			int x = q[q2++];
			for (int i = 0; i < sz; i++) {
				unsigned int t = need[i] & ed[x][i];
				if (t != 0) for (int j = 0; j < 32; j++) if (t & pw(j)) {
					need[i] ^= pw(j);
					q[q1++] = i * 32 + j;
				}
			}
		}
		for (int j = 0; j < n + n; j++) if (need[j >> 5] & pw(j & 31)) d[i][j] = 0; else d[i][j] = 1;
	}
}

vector<int> order;
int was[2016];

int ans[2016];

void go(int x) {
	was[x] = 1;
	for (int i = 0; i < n + n; i++) if (d[i][x] && !was[i]) go(i);
	order.pb(x);
}

void col(int x, int o) {
	if (was[x]) return;
	was[x] = o;
	for (int i = 0; i < n + n; i++) if (d[x][i]) col(i, o);

}

void solve(int A, int B) {
	for (int i = 0; i < n + n; i++) for (int j = 0; j < 80; j++) ed[i][j] = 0;

	for (int i = 0; i < m[A]; i++) {
		int a = getv(x[A][i]);
		int b = getv(y[A][i]);

		ae(NOT(a), b);
		ae(NOT(b), a);
	}
	findd();

/*	for (int i = 0; i < n + n; i++) {
		for (int j = 0; j < n + n; j++) cout << d[i][j];
		cout << endl;
	}*/
	int good = 1;
	for (int i = 0; i < n; i++) if (d[i][NOT(i)] && d[NOT(i)][i]) good = 0;
	if (!good) return;

	for (int i = 0; i < m[B]; i++) {
		int a = getv(x[B][i]);
		int b = getv(y[B][i]);


		//new a -> NOT(a)
		//new b -> NOT(b)

		int bad = 0;

		if (d[NOT(a)][a] || d[NOT(b)][b]) bad = 1;

		if (d[NOT(a)][b] && d[NOT(b)][a]) bad = 1;

		if (d[NOT(b)][a] && d[NOT(a)][b]) bad = 1;

		if (!bad) {
			ae(a, NOT(a));
			ae(b, NOT(b));

			findd();
/*	for (int i = 0; i < n + n; i++) {
		for (int j = 0; j < n + n; j++) cout << d[i][j];
		cout << endl;
	}*/
			for (int i = 0; i < n + n; i++) was[i] = 0;
			order.clear();
			for (int i = 0; i < n + n; i++) if (!was[i]) go(i);

			int cc = 0;
			for (int i = 0; i < n + n; i++) was[i] = 0;
			for (int i = order.size() - 1; i >= 0; i--) {
				int t = order[i];
				if (was[t]) continue;
				cc++;
				col(t, cc);
			}
/*			cout << "add " << a << " " << NOT(a) << endl;
			cout << "add " << b << " " << NOT(b) << endl;

			for (int i = 0; i < n + n; i++) cout << was[i] << " ";
			cout << endl;*/

			for (int i = 0; i < n; i++) {
				ans[i] = (was[i] < was[NOT(i)]);
				cout << ans[i];
				if (i + 1 == n) cout << endl; else cout << " ";
			}

			exit(0);
		}
	}

}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	cin >> n >> m[0] >> m[1];

	for (int i = 0; i < 2; i++) for (int j = 0; j < m[i]; j++) scanf("%d%d", &x[i][j], &y[i][j]);

	solve(0, 1);
	solve(1, 0);

	puts("SIMILAR");

	return 0;
}