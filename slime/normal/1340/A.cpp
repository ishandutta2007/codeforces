//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

using namespace std;
multiset<int> s;
int fa[maxn];
int sz[maxn];
int n;
int p[maxn];
int pl[maxn];
int gfa(int x) {
	if (fa[x] == x) return x;
	return fa[x] = gfa(fa[x]);
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		s.clear();
		scanf("%d", &n);
		fa[n + 1] = n + 1;
		for (int i = 1; i <= n ;i++) {
			scanf("%d", &p[i]), 
			pl[p[i]] = i;
			fa[i] = i, 
			sz[i] = 1, 
			s.insert(1);
		}
		int fl = 1;
		for (int i = 1; i <= n; i++) {
			int nx = pl[i];
			if (*(--s.end()) != (sz[nx])) fl = 0;
			int ed = gfa(nx + 1);
			fa[nx] = ed;
			s.erase(s.find(sz[nx]));
			if (ed <= n) {
				s.erase(s.find(sz[ed]));
				sz[ed] += sz[nx];
				s.insert(sz[ed]);
			}
		}
		if (fl) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}