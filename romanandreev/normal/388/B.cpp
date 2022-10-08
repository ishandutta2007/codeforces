#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<map>
#include<algorithm>
#include<cstring>
#include<set>
#include<ctime>
#include<cassert>


using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),(a).end()
typedef pair<pair<int, int>, vector<vector<int> > > graph;
char a[5000][5000];
graph mul(graph g1, int k) {
	int no = g1.x.x;
	int nn = g1.x.x + k + 1;
	vector<vector<int> > m(nn);
	for (int i = 0; i < nn; i++) {
		for (int j = 0; j < nn; j++) {
			if (i < no && j < no) {
				m[i].pb(g1.y[i][j]);
			} else {
				m[i].pb(0);
			}
		}
	}
	for (int i = 0; i < k; i++) {
		m[no - 1][no + i] = m[no + i][no - 1] = 1;
		m[nn - 1][no + i] = m[no + i][nn - 1] = 1;
	}
	return mp(mp(nn, g1.x.y + 2), m);
}
graph add(graph g1, int k) {
	if (k == 0) {
		return g1;
	}
	g1 = add(g1, k - 1);
	int no = g1.x.x;
	int nn = g1.x.x + g1.x.y - 1;
	vector<vector<int> > m(nn);
	for (int i = 0; i < nn; i++) {
		for (int j = 0; j < nn; j++) {
			if (i < no && j < no) {
				m[i].pb(g1.y[i][j]);
			} else {
				m[i].pb(0);
			}
		}
	}
	for (int i = 0; i < g1.x.y; i++) {
		int a = no + i - 1;
		int b = no + i;
		if (i == 0) {
			a = 0;
		}
		if (i == g1.x.y - 1) {
			b = no - 1;
		}
		m[a][b] = m[b][a] = 1;
	}
	for (int i = 0; i < nn; i++) if (i != no - 1 && i != nn - 1){
		swap(m[no - 1][i], m[nn - 1][i]);
		swap(m[i][no - 1], m[i][nn - 1]);
	}
	return mp(mp(nn, g1.x.y), m);
}

graph gen(int k) {
	if (k == 1) {
		vector<vector<int> > vv(3);
		vv[0].pb(0);
		vv[0].pb(1);
		vv[0].pb(0);
		vv[1].pb(1);
		vv[1].pb(0);
		vv[1].pb(1);
		vv[2].pb(0);
		vv[2].pb(1);
		vv[2].pb(0);
		return mp(mp(3, 2), vv);
	}
	graph g1 = gen(k / 2);
	g1 = mul(g1, 2);
	if (k % 2 == 1) {
		return add(g1, 1);	
	} else {
		return g1;
	}
}
int main() {
	#ifdef home
    	freopen("a.in", "r", stdin);
	    freopen("a.out", "w", stdout);
	#endif
	int k;
	cin>>k;
	graph g = gen(k);
	int nn = g.x.x;
	int no = 1;
	for (int i = 0; i < nn; i++) if (i != no && i != nn - 1){
		swap(g.y[no][i], g.y[nn - 1][i]);
		swap(g.y[i][no], g.y[i][nn - 1]);
	}
	printf("%d\n", nn);
	for (int i = 0; i < nn; i++) {
		for (int j = 0; j < nn; j++) {
			if (g.y[i][j] == 0) {
				printf("N");
			} else {
				printf("Y");
			}
		}
		printf("\n");
	}
	return 0;
}