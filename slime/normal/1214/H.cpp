#include <bits/stdc++.h>
#define vi vector<int>
#define maxn 400005
#define ll long long
#define ld double
#define mod 998244353
#define pb push_back
using namespace std;
int col[maxn];
vi eg[maxn];
int dep[maxn], q[maxn], ed = 0;
int mxs = 0;
int n, k;
int ns[maxn], pre[maxn];

void dfs(int a, int fa) {
//	cout << "!!!" << a << ' ' << fa << endl;
	pre[a] = fa;
	q[ed++] = a;
	if (dep[a] > dep[mxs]) mxs = a;
	for (int i = 0; i < eg[a].size(); i++) {
		int v = eg[a][i];
		if (v == fa) continue;
		dep[v] = dep[a] + 1;
		dfs(v, a);
	}
}
int main()
{
	// ! k = 2
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		eg[u].pb(v), eg[v].pb(u);
	}
	ed = 0, mxs = 0;
	dep[1] = 1;
	dfs(1, 0);
	if (k == 2) {
		cout << "Yes\n";
		for (int i = 1; i <= n; i++)
			if (dep[i] & 1) printf("1 ");
			else printf("2 ");
		return 0;
	}
	

	int rt = mxs;	
	ed = 0, mxs = 0;
	dep[rt] = 1;
	dfs(rt, 0);
	int qr = mxs;
	int cnt = 0;
	while(1) {
		ns[cnt++] = qr;
		if (qr == rt) break;
		qr = pre[qr];
	}
//	cout << rt << ' ' << mxs << endl;
//	cout << cnt << endl;
	reverse(ns, ns + cnt);
	for (int i = 0; i < cnt; i++)
		col[ns[i]] = (i % k) + 1;
	for (int i = 0; i < cnt; i++) {
	//	cout << i << ' ' << ns[i] << endl;
		int nr = ns[i];
		for (int j = 0; j < eg[nr].size(); j++) {
			int v = eg[nr][j];
			if (i && v == ns[i - 1]) continue;
			if (v == ns[i + 1]) continue;
			dep[v] = 1, ed = 0, mxs = 0;
			dfs(v, nr);
		//	cout << nr << ' ' << v << ' ' << i << endl;
			if (dep[mxs] + min(i + 1, cnt - i) >= k) {
				cout << "No" << endl;
				return 0;
			}
			else {
				if (i < cnt - 1 - i)
					for(int j = 0; j < ed; j++) {
						int npl = q[j];
					//	cout << "COL" << 
						col[npl] = col[ns[i - dep[npl]]];
					}
				else
					for (int j = 0; j < ed; j++) {
						int npl = q[j];
						col[npl] = col[ns[i + dep[npl]]];
					}
			}
		}
	}
	cout << "Yes" << endl;
	for (int i = 1; i <= n; i++)
		printf("%d ", col[i]);
	return 0;
}