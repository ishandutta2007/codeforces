#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
#include <random>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	random_device rd;
	mt19937 mt(rd());
	int N, M; cin >> N >> M;
	vector<int> a(M), b(M);
	vector<vector<int> > G(N);
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &a[i], &b[i]);
		a[i]--; b[i]--;
		G[a[i]].push_back(b[i]);
		G[b[i]].push_back(a[i]);
	}
	int T = 0;
	vector<vector<int> > p(N);
	for (int u = 0; u < N; u++) {
		int k; scanf("%d", &k);
		while (k--) {
			int t; scanf("%d", &t);
			t--;
			T = max(T, t + 1);
			p[u].push_back(t);
		}
	}
	vector<int> c(N);
	for (int u = 0; u < N; u++) {
		if (T > p[u].size()) {
			set<int> st;
			for (int v: G[u])
				if (v < u)
					st.insert(c[v]);
			for (int t: p[u])
				if (!st.count(t)) {
					c[u] = t;
					break;
				}
		}
		else {
			vector<int> num(T);
			for (int v: G[u])
				if (v < u)
					num[c[v]]++;
			int t0 = 0;
			for (int t = 0; t < T; t++)
				if (num[t] < num[t0])
					t0 = t;
			c[u] = t0;
		}
	}
	vector<map<int, int> > unko(T);
	for (int u = 0; u < N; u++)
		for (int v: G[u])
			unko[c[u]][c[v]]++;
	vector<int> C(T);
	for (int t = 0; t < T; t++) {
		vector<int> num(2);
		for (i_i z: unko[t]) {
			int s = z.first;
			if (s < t) num[C[s]] += z.second;
		}
		if (num[0] < num[1]) C[t] = 0;
		else C[t] = 1;
	}
	for (int u = 0; u < N; u++)
		printf("%d ", c[u] + 1);
	cout << endl;
	for (int t = 0; t < T; t++)
		printf("%d ", C[t] + 1);
	cout << endl; 
}