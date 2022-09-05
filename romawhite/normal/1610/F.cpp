#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>  
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <time.h>
#include <bitset>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b) - 1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))
 
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair
 
typedef long long Int;
typedef vector<int> VI;
typedef pair<int, int> PII;
 
const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000;
const Int LINF = INF * (Int) INF;
const int MAX = 300007;
const int MOD = 1000000007;

vector<PII> G[2][MAX];
PII E[MAX];
int R[MAX];
int IDX[MAX];

int U[MAX];

void Set(int index, int from, int to) {
	// cout << index << ' ' << from << ' ' << to << endl;
	if (MP(from, to) == E[index])
		R[index] = 1;
	else
		R[index] = 2;
}

int dfs_c(int v, int t, int p = -1) {
	U[v] = 1;
	FOR(i,IDX[v],SZ(G[t][v])) {
		int edge = G[t][v][i].second;
		if (R[edge] != 0)
			continue;
		int to = G[t][v][i].first;
		if (edge == p)
			continue;
		if (U[to] == 2) {
			continue;
		}
		if (U[to] == 1) {
			Set(edge, v, to);
			U[v] = 0;
			return to;
		}
		int r = dfs_c(to, t, edge);
		if (r != -1) {
			Set(edge, v, to);
		}
		if (r != -1 && r != v) {
			U[v] = 0;
			return r;
		}
		IDX[v] = i + 1;
	}
	U[v] = 2;
	return -1;
}

vector<pair<PII, VI > > X;

PII P[MAX];

void F(int v, int a, int b) {
	VI R;
	PII c = MP(a, b);
	while (a != v) {
		R.push_back(P[a].second);
		a = P[a].first;
	}
	VI RR;
	while (b != v) {
		RR.push_back(P[b].second);
		b = P[b].first;
	}
	reverse(ALL(RR));
	for(auto x: RR)
		R.push_back(x);
	X.push_back(MP(c, R));
}

int dfs(int v, int t, int p = -1, int p_edge = -1) {
	U[v] = 1;
	int last = -1;
	P[v] = MP(p, p_edge);
	FOR(i,0,SZ(G[t][v])) {
		int edge = G[t][v][i].second;
		int to = G[t][v][i].first;
		if (R[edge])
			continue;
		if (U[to])
			continue;
		int r = dfs(to, t, v, edge);
		if (last == -1) {
			last = r;
		} else {
			F(v, last, r);
			last = -1;
		}
	}
	
	if (last != -1 && p == -1) {
		F(v, last, v);
		return -1;
	}
	if (last == -1)
		last = v;
	return last;
}

vector<PII> GG[MAX];
PII rev[MAX];

void dfs_rev(int v, int p = -1) {
	U[v] = 1;
	FOR(i,0,SZ(GG[v])) {
		int to = GG[v][i].first;
		int x = GG[v][i].second;
		if (to == p)
			continue;
		rev[x] = MP(v, to);
		if (!U[to])
			dfs_rev(to);
	}
}

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n, m;
	cin >> n >> m;

	FOR(i,0,m) {
		int a, b, c;
		cin >> a >> b >> c;
		--a; --b; --c;
		G[c][a].push_back(MP(b, i));
		G[c][b].push_back(MP(a, i));
		E[i] = MP(a, b);
	}


	FILL(U, 0);
	FILL(IDX, 0);
	FOR(i,0,n) {
		if (!U[i])
			dfs_c(i, 0);
	}
	FILL(U, 0);
	FILL(IDX, 0);
	FOR(i,0,n) {
		if (!U[i])
			dfs_c(i, 1);
	}
	// cout << "!!!" << endl;

	FILL(U, 0);
	FOR(i,0,n) {
		if (!U[i])
			dfs(i, 0);
	}
	FILL(U, 0);
	FOR(i,0,n) {
		if (!U[i])
			dfs(i, 1);
	}

	FOR(i,0,SZ(X)) {
		PII p = X[i].first;
		// cout << p.first << ' ' << p.second << "   ";
		VI R = X[i].second;
		// FOR(i,0,SZ(R)) {
		// 	cout << R[i] << ' ';
		// }
		// cout << endl;
		GG[p.first].push_back(MP(p.second, i));
		GG[p.second].push_back(MP(p.first, i));
	}

	FILL(U, 0);
	FOR(i,0,n)
		if (!U[i] && SZ(GG[i]) == 1)
			dfs_rev(i);
	FOR(i,0,n)
		if (!U[i])
			dfs_rev(i);
	
	FOR(i,0,SZ(X)) {
		PII p = rev[i];
		PII q = X[i].first;
		VI R = X[i].second;
		if (p != q)
			reverse(ALL(R));
		int v = p.first;
		FOR(i,0,SZ(R)) {
			int to = (v ^ E[R[i]].first ^ E[R[i]].second);
			Set(R[i], v, to);
			v = to;
		}
	}

	int cnt = 0;
	FOR(i,0,n) {
		if (G[0][i].size() % 2 == 1)
			++ cnt;
	}
	cout << cnt << endl;
	FOR(i,0,m) {
		cout << R[i];
	}
	cout << endl;



    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}