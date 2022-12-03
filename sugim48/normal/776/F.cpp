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

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

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

struct union_find {
	vector<int> v;
	union_find(int n) : v(n, -1) {}
	int find(int x) { return v[x] < 0 ? x : v[x] = find(v[x]); }
	void unite(int x, int y) {
		x = find(x); y = find(y);
		if (x == y) return;
		if (-v[x] < -v[y]) swap(x, y);
		v[x] += v[y]; v[y] = x;
	}
	bool root(int x) { return v[x] < 0; }
	bool same(int x, int y) { return find(x) == find(y); }
	int size(int x) { return -v[find(x)]; }
};

vector<int> E[100001];
char C[100001];
int num[100001];
char CN[100001];

int dfs_num(int cur,int pre) {
	int i;
	int ma=-1;
	
	num[cur]=1;
	rep(i,E[cur].size()) {
		int tar=E[cur][i];
		if(tar==pre) continue;
		if(C[tar]) CN[cur] = max(CN[cur],C[tar]);
		else num[cur]+= dfs_num(tar,cur), CN[cur] = max(CN[cur],CN[tar]);
	}
	return num[cur];
}

pair<int,int> dfs_center(int cur,int pre,int nu) {
	int i;
	pair<int,int> res=make_pair(1<<30,-1);
	int ma=0,c=1;
	
	rep(i,E[cur].size()) {
		int tar=E[cur][i];
		if(tar==pre || C[tar]) continue;
		res=min(res,dfs_center(tar,cur,nu));
		
		ma=max(ma,num[tar]);
		c+=num[tar];
	}
	return min(res,make_pair(max(ma,nu-c),cur));
}

int main() {
	int N, M; cin >> N >> M;
	vector<int> a, b;
	rep(i, N) a.pb(i), b.pb((i + 1) % N);
	rep(j, M) {
		int i1, i2; scanf("%d%d", &i1, &i2);
		i1--; i2--;
		a.pb(i1); b.pb(i2);
	}
	M = a.size();
	vector<vector<i_i> > G(N);
	rep(j, M) {
		G[a[j]].pb(i_i(b[j], j));
		G[b[j]].pb(i_i(a[j], j + M));
	}
	union_find uf(M * 2);
	rep(i, N) {
		vector<i_i> v = G[i];
		for (i_i& p: v) if (p.first < i) p.first += N;
		sort(v.begin(), v.end());
		for (int k = 0; k + 1 < v.size(); k++) {
			uf.unite(v[k].second, (v[k + 1].second + M) % (M * 2));
		}
	}
	int L = 0;
	vector<int> index(M * 2);
	rep(j, M * 2) if (uf.root(j) && uf.size(j) > 1) index[j] = L++;
	for (int j = N; j < M; j++) {
		int u = index[uf.find(j)], v = index[uf.find(M + j)];
		E[u].pb(v); E[v].pb(u);
		// cout << u << ' ' << v << endl;
	}
	// cout << L << endl;
	rep(i,L) {
		while(C[i]==0) {
			dfs_num(i,-1);
			pair<int,int> p=dfs_center(i,-1,num[i]);
			C[p.second] = CN[i]+1;
			if(C[p.second]==1) C[p.second]='A';
			if(p.first==0) break;
		}
	}
	vector<vector<int> > vs(L);
	rep(j, M * 2) {
		if (uf.size(j) == 1) continue;
		int u = index[uf.find(j)];
		vs[u].pb(a[j % M]); vs[u].pb(b[j % M]);
	}
	vector<pair<vector<int>, int> > hoge(L);
	rep(u, L) {
		vector<int> unko = vs[u];
		sort(unko.begin(), unko.end());
		unko.erase(unique(unko.begin(), unko.end()), unko.end());
		reverse(unko.begin(), unko.end());
		hoge[u] = make_pair(unko, u);
	}
	sort(hoge.begin(), hoge.end());
	rep(u, L) printf("%d ", C[hoge[u].second] - 'A' + 1);
	cout << endl;
}