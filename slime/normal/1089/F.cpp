#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
#define priority_queue __gnu_pbds::priority_queue
typedef long long LL;
typedef long double LD;
typedef unsigned int ui;
typedef unsigned long long ul;
#define ri register int
#define pb push_back
#define fi first
#define se second
#define mid ((l + r) >> 1)
#define ls (i << 1)
#define rs (i << 1 | 1)
#define enum(i, j, k) for(int i = j; i <= k; i ++)
#define FO(x) { freopen(#x".in", "r", stdin); freopen(#x".out", "w", stdout); }
using namespace std;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<int, LL> pil;
typedef pair<LL, int> pli;
typedef vector<int> vi;
#define ae(x) for(node *p = h[x]; p; p = p->nxt)
#define G \
	struct node { int v; node *nxt; } e[maxm], *h[maxn]; int z;\
	void adde(int u, int v) { e[++z].v = v; e[z].nxt = h[u]; h[u] = &e[z]; }\
	void addrev(int u, int v) { adde(u, v); adde(v, u); }
#define W \
	struct node { int v, w; node *nxt; } e[maxm], *h[maxn]; int z;\
	void adde(int u, int v, int w) { e[++z].v = v; e[z].w = w; e[z].nxt = h[u]; h[u] = &e[z]; }\
	void addrev(int u, int v, int w) { adde(u, v, w); adde(v, u, w); }
inline int _() // ret >= 0
{
	int ret = 0; char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	do { ret = ret * 10 + ch - '0'; ch = getchar(); } while('0' <= ch && ch <= '9');
	return ret;
}
inline void _(int x) // x >= 0
{
	if(x < 10) { putchar(x + '0'); return ; }
	_(x / 10); putchar(x % 10 + '0');
}
void What_are_you_doing_at_the_end_of_the_world_Are_you_busy_Can_you_save_us()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(16);
}
/* Default Code Ends Here. */

void no()
{
	cout << "NO" << endl;
	exit(0);
}

int n;
vi v;
bool dp[100100];
bool vis[40100];
int nxt[100100];
queue<int> que;
int main()
{
	What_are_you_doing_at_the_end_of_the_world_Are_you_busy_Can_you_save_us();
	
	cin >> n;
	enum(i, 2, sqrt(n))
		if(n % i == 0)
		{
			v.pb(i);
			if(n / i != i)
				v.pb(n / i);
		}
	if(v.empty())
		no();
	sort(v.begin(), v.end());
	dp[0] = true;
	int m = v[0];
	for(int i : v)
	{
		if(i % m == 0)
			continue;
		memset(vis, 0, sizeof vis);
		enum(j, 0, m - 1)
			if(dp[j] && !vis[j])
			{
				int t = j;
				for( ; !vis[t]; t = (t + i) % m)
					vis[t] = true;
			}
		enum(j, 0, m - 1)
			if(!dp[j] && vis[j])
			{
				dp[j] = true;
				nxt[j] = i;
			}
	}
	if(!dp[m - 1])
		no();
	
	int d = n - 1;
	for(int i = m - 1; i; i = ((i - nxt[i]) % m + m) % m)
	{
		que.push(nxt[i]);
		d -= nxt[i];
	}
	if(d < 0)
		while(true);
	cout << "YES" << endl;
	cout << que.size() + (d != 0) << endl;
	if(que.size() + (d != 0) > 100000)
		while(true)
			putchar('a');
	while(!que.empty())
	{
		cout << 1 << ' ' << n / que.front() << endl;
		que.pop();
	}
	if(d != 0)
		cout << d / m << ' ' << n / m << endl;
	return 0;
}