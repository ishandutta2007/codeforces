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
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define M 1000000007
#define N 1511111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int n, m, V1, V2;

char type[N];
int x[N], y[N];

int in1[N], in2[N], out1[N], out2[N];

int n1[N], n2[N];

int par1[N], par2[N];

pair<int, int> chi1[N], chi2[N];

long long su[N], ans[N];

vector<int> po[N];

int T;

int tz[N];


void add(int x, int v) {
	while (x < n) {
		su[x] += v;
		x |= (x + 1);		
	}
}

long long fin(int x) {
	long long r = 0;
	while (x >= 0) {
		r += su[x];
		x = (x & (x + 1)) - 1;
	}
	return r;
}



void go1(int x) {
	in1[x] = T;
	if (x < n) T++; else {

		go1(chi1[x].F);
		go1(chi1[x].S);
	}		

	out1[x] = T - 1;
}

void go2(int x) {
	in2[x] = T;
	if (x < n) T++; else {

		go2(chi2[x].F);       
		go2(chi2[x].S);
	}		

	out2[x] = T - 1;
}


int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	scanf("%d%d\n", &n, &m);


	for (int i = 0; i < m; i++) {
		scanf("%c", &type[i]);
		if (type[i] == 'A' || type[i] == 'Z' || type[i] == 'Q') {
			scanf("%d\n", &x[i]);
			x[i]--;
		} else {
			scanf("%d%d\n", &x[i], &y[i]);
			x[i]--;
			y[i]--;
		}
	}
	V1 = V2 = n;
	for (int i = 0; i < n; i++) {
		n1[i] = n2[i] = i;
	}

	for (int i = 0; i < m; i++) {
		if (type[i] == 'U') {
			chi1[V1] = mp(n1[x[i]], n1[y[i]]);

			par1[n1[x[i]]] = V1;
			par1[n1[y[i]]] = V1;
			n1[x[i]] = V1;
			n1[y[i]] = V1;
			V1++;
		}
		if (type[i] == 'M') {
			chi2[V2] = mp(n2[x[i]], n2[y[i]]);

			par2[n2[x[i]]] = V2;
			par2[n2[y[i]]] = V2;
			n2[x[i]] = V2;
			n2[y[i]] = V2;
			V2++;
		}
	}
	T = 0;
	for (int i = 0; i < V1; i++) if (par1[i] == 0) go1(i);
	T = 0;
	for (int i = 0; i < V2; i++) if (par2[i] == 0) go2(i);

	for (int i = 0; i < n; i++) {
		n2[i] = i;
	}

	for (int i = 0; i < m; i++) {
		if (type[i] == 'M') {
			n2[x[i]] = par2[n2[x[i]]];
			n2[y[i]] = par2[n2[y[i]]];
		}
		if (type[i] == 'Z') {
			tz[i] = n2[x[i]];
		}
	}
	set<pair<int, int> > Q;
	set<pair<int, int> >::iterator it, it2;
	for (int i = m - 1; i >= 0; i--) {
		if (type[i] == 'Q') {
			Q.insert(mp(in2[x[i]], i));
		}
		if (type[i] == 'Z') {
			int A = in2[tz[i]];
			int B = out2[tz[i]];
			it = Q.lower_bound(mp(A, 0));
			while (it != Q.end() && (it -> F) <= B) {
				po[i].pb(it -> S);
				it2 = it;
				it++;
				Q.erase(it2);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		n1[i] = i;
	}

	for (int i = 0; i < m; i++) {
		if (type[i] == 'U') {
			n1[x[i]] = par1[n1[x[i]]];
			n1[y[i]] = par1[n1[y[i]]];			
		}
		if (type[i] == 'A') {
			int sz = out1[n1[x[i]]] - in1[n1[x[i]]] + 1;
			add(in1[n1[x[i]]], sz);
			add(out1[n1[x[i]]] + 1, -sz);
		}
		for (int j = 0; j < po[i].size(); j++) {
			int v = in1[x[po[i][j]]];
			ans[po[i][j]] -= fin(v);
		}
		if (type[i] == 'Q') {
			int v = in1[x[i]];
			ans[i] += fin(v);
		}
	}
	for (int i = 0; i < m; i++) if (type[i] == 'Q') printf("%I64d\n", ans[i]);

	return 0;
}