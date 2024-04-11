//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int n, m, q;
map<string, int> mp;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Dsu {
	int fa[N<<1], rk[N<<1];
	void init(int x) {rep(i, 1, x) fa[i] = i, rk[i] = 1;}
	int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
	bool merge(int x, int y) {
		int u = find(x), v = find(y);
		if(u == v) return 0;
		if(rk[u] < rk[v]) swap(u, v);
		fa[v] = u;
		chkmax(rk[u], rk[v]+1);
		return 1;
	}
}dsu;

int main() {
	scanf("%d%d%d", &n, &m, &q);
	rep(i, 1, n) {
		string s;
		cin >> s;
		mp[s] = i;
	}
	dsu.init(2*n);
	rep(i, 1, m) {
		int op;
		string s, t;
		cin >> op >> s >> t;
		int u = mp[s], v = mp[t];
		if(op == 1) {
			if(dsu.find(u) == dsu.find(v+n)) puts("NO");
			else {
				puts("YES");
				dsu.merge(u, v);
				dsu.merge(u+n, v+n);
			}
		}
		else {
			if(dsu.find(u) == dsu.find(v)) puts("NO");
			else {
				puts("YES");
				dsu.merge(u, v+n);
				dsu.merge(u+n, v);
			}
		}
	}
	rep(i, 1, q) {
		string s, t;
		cin >> s >> t;
		int u = mp[s], v = mp[t];
		if(dsu.find(u) == dsu.find(v)) puts("1");
		else if(dsu.find(u) == dsu.find(v+n)) puts("2");
		else puts("3");
	}
	return 0;
}