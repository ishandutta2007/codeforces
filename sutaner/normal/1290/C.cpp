#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define lowbit(x) (x & -x)
#define pb push_back
#define maxn 600020 
using namespace std;

/*struct edge{
	int next, to;
	bool len;
	edge(int next, int to, bool len) : next(next), to(to), len(len){}
	edge(){}
}
int cnt = 1, h[maxn];
void Add_Edge(int x, int y, bool z){
	e[++cnt] = edge(h[x], y, z);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x, z);
	h[y] = cnt;
}*/

int n, m;
int bel[maxn];
char s[maxn];

struct edge{
	int x, y, len, id;
	edge(int x, int y, int len, int id) : x(x), y(y), len(len), id(id){}
	edge(){}
	bool operator < (const edge b) const{
		return id < b.id;
	}
}e[maxn];
int cnt = 0;

//vector<int> lis[maxn];
//int id[maxn], mi[maxn], num[maxn][2], ufs[maxn];
//bool vis[maxn];
int num[maxn][2], ufs[maxn], fix[maxn], v[maxn], d[maxn];
int find_root(int x){
	if (ufs[x] == x) return x;
	int _ufs = find_root(ufs[x]);
	v[x] = v[ufs[x]] ^ d[x];
	ufs[x] = _ufs;
	d[x] = v[x] ^ v[ufs[x]];
	return ufs[x];
	//return ufs[x] = (ufs[x] == x) ? x : find_root(ufs[x]);
}
//int liss[maxn];
//bool cmp(const int i, const int j){
//	return mi[i] < mi[j];
//}
int ans = 0;
void Add_Edge(int id){
	int x = e[id].x, y = e[id].y, z = e[id].len;
	if (x == y){
		int rx = find_root(x);
		if (fix[rx] != -1) return;
		ans -= min(num[rx][0], num[rx][1]);
		v[rx] = ((z == v[x]) ? v[rx] : (1 ^ v[rx]));
		fix[rx] = v[rx];
		if (v[rx]) swap(num[rx][0], num[rx][1]);
		ans += num[rx][1];
	}
	else {
		int _x = x, _y = y;
		x = find_root(_x), y = find_root(_y);
		z ^= v[_x] ^ v[x] ^ v[_y] ^ v[y];
		if (x == y) return;
		else {
			if (fix[x] != -1 && fix[y] != -1){
				ufs[x] = y;
				d[x] = z;
				//v[x] = v[y] ^ z;
				//update(ans);
				num[y][0] += num[x][0], num[y][1] += num[x][1];
			}
			else if (fix[x] != -1 || fix[y] != -1){	
				if (fix[x] != -1) swap(x, y); // fix[y] != -1;
				ufs[x] = y;
				v[x] = v[y] ^ z;
				if (v[x]) swap(num[x][0], num[x][1]);
				d[x] = z;
				ans -= min(num[x][0], num[x][1]);
				ans -= num[y][1];
				num[y][0] += num[x][0], num[y][1] += num[x][1];
				ans += num[y][1];
			} 
			else {
				ufs[x] = y;
				d[x] = v[x] = z; 
				if (v[x]) swap(num[x][0], num[x][1]);
				ans -= min(num[x][0], num[x][1]);
				ans -= min(num[y][0], num[y][1]);
				num[y][0] += num[x][0], num[y][1] += num[x][1];
				ans += min(num[y][0], num[y][1]);
			}
		}
	}
}
int main(){
	
		//freopen("C.in", "r", stdin);
		
	int k, x;
	scanf("%d%d", &n, &m);
	rep(i, 1, n) bel[i] = -1;
	rep(i, 1, m) ufs[i] = i, v[i] = d[i] = 0, fix[i] = -1, num[i][0] = 1, num[i][1] = 0; //id[i] = n + 1;
	scanf("%s", s + 1); 
	rep(i, 1, m){
		scanf("%d", &k);
		rep(j, 1, k) {
			scanf("%d", &x);
			//id[i] = min(id[i], x);
			if (bel[x] == -1) bel[x] = i;
			else {
				//Add_Edge(bel[x], i, (s[x] == '0')); 
				e[++cnt] = edge(bel[x], i, (s[x] == '0'), x);
				bel[x] = -1;
			}
		} 
	}
	rep(x, 1, n) if (bel[x] != -1) e[++cnt] = edge(bel[x], bel[x], (s[x] == '0'), x); 
	sort(e + 1, e + 1 + cnt);
	int ptr = 1;
	rep(i, 1, n){
		while (ptr <= n && e[ptr].id == i) Add_Edge(ptr), ptr++; 
		printf("%d\n", ans);
	}
	/*
	rep(x, 1, n) mi[x] = id[x]; erep(i, x) mi[x] = min(mi[x], id[e[i].to]), liss[x] = x;
	sort(liss + 1, liss + 1 + n);
	rep(i, 1, n) x = liss[i], lis[id[x]].pb(x); 
	rep(t, 1, n){
		int si = lis[t].size();
		srep(j, 0, si){
			int x = lis[t][j];
			erep(i, x){
				int op = e[i].to;
				if (op == 
			}
		}
	}
	*/
	return 0;
}