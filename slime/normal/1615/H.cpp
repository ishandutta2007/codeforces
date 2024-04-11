//Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 1000000007
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 1005;
const int maxm = 100005;
struct edge
{
	int u, v, c;
	edge *rev;
	edge *next;
}pool[maxm * 2], *h[maxn];
int cnt = 0;
void addedge(int u, int v, int c)
{
	//cout<<"ADE"<<u<<" "<<v<<" "<<c<<endl;
	edge *new1 = &pool[cnt++];
	new1->u = u, new1->v = v, new1->c = c;
	
	edge *new2 = &pool[cnt++];
	new2->u = v, new2->v = u, new2->c = 0;
	
	new1->rev = new2, new2->rev = new1;
	new1->next = h[u], h[u] = new1;
	new2->next = h[v], h[v] = new2;
}
int level[maxn], q[maxn], fr, ed;
int s, t;
void bfs()
{
	fr = ed = 0;
	memset(level, -1, sizeof(level));
	level[s] = 1, q[ed++] = s;

	while(fr < ed)
	{
		for(edge *p = h[q[fr]]; p; p = p->next)
		{
			if(!p->c || level[p->v] != -1) continue;
			level[p->v] = level[q[fr]] + 1, q[ed++] = p->v;
		}
		fr++;
	}
}
int dfs(int a, int flow)
{
	if(!flow) return 0;
	if(a == t) return flow;
	int nf = 0;
	for(edge *p = h[a]; p; p = p->next)
	{
		if((level[p->v] != level[a] + 1) || (p->c <= 0)) continue;
		int nflow = dfs(p->v, min(flow - nf, p->c));
		nf += nflow, p->c -= nflow, p->rev->c += nflow;
	}
	if(!nf) level[a] = -1;
	return nf;
}
int dinic()
{
	int ans = 0;
	while(1)
	{
		bfs();
		int nans = dfs(s, 1e9);
		if(!nans) break;
		ans += nans;
	}
	return ans;
}
void init() {
	for (int i = 0; i < maxn; i++) h[i] = NULL;
	cnt = 0;
}

vi eg[maxn];
int a[maxn];
int n, m;

int fl[maxn];
int tt = 1e9;
void otp(vi a) {
	for (auto v : a) cout << v << ' '; cout << endl;
}
vi cal(vi x, int b) {
	// check what <= b
	init();
	s = n + 1, t = n + 2;
	tt += 1;
	for (auto v : x) fl[v] = tt;
	for (auto v : x) {
		for (auto s : eg[v]) {
			if (fl[s] != tt) continue;
			// v -> s
			addedge(v, s, 1e9);
		}
		if (a[v] <= b) addedge(s, v, 1);
		else addedge(v, t, 1);
	}
	dinic();
	bfs();
	vi res;
	for (auto v : x) 
		if (level[v] != -1)	res.pb(v);
	return res;
}
void work(vi x, int l, int r) {
	if (l == r) {
		for (auto v : x) a[v] = l;
		return ;
	}
	if (!x.size()) return ;
	int mid = (l + r) >> 1;
	if (mid == r) mid -= 1;
	vi cr = cal(x, mid);
	for (auto v : x) fl[v] = 1;
	for (auto v : cr) fl[v] = 0;
	vi rs; 
	for (auto v : x)
		if (fl[v]) rs.pb(v);
	work(cr, l, mid);
	work(rs, mid + 1, r);
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		eg[v].pb(u);
	}
	vi cur;
	for (int i = 1; i <= n; i++)
		cur.pb(i);
	work(cur, -1e9 - 10, 1e9 + 10);
	for (int i = 1; i <= n; i++)
		cout << a[i] << ' ';
    return (0-0); //<3
}