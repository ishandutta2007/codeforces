#include<bits/stdc++.h>
using namespace std;
#define rep(i,s,t) for (int i=s;i<=t;i++)
#define pi acos(-1)
#define FOR(i,s,t) for (int i = s; i < t; i++)
typedef long long LL;
typedef long double LD;
typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef pair<PII, PII> PPP;
typedef pair<PII, int> PPI;
typedef pair<LL, PII> PLP;
typedef pair<double, PII> PDP;
#define repp(i,s,t) for (int i=s;i>=t;i--)
template<class T> T sqr(T x) {return x*x;}
#define debug(x) cerr<<#x"="<<(x)<<endl;
#define pb(x) push_back(x);
#define ori(x) x-'a'
#define y0 AERGAEWFAWERAw
#define y1 ASDFAEWRWERWERW
#define x0 gggsdfsfsfdf
#define x1 SAFREWRREWR
const int maxn = 4001;
char sp[maxn];
struct edges{int v, flow, rev; int cost;} mm;
vector<int> ans[maxn];
vector<edges> g[maxn];
int dist[maxn];
bool vis[maxn];
int n, m, st, en;
char str[maxn];
struct pairs{int x, y;} pre[maxn];
const int inf = 1e9;
int A[maxn], B[maxn];
inline bool spfa()
{
	rep(i,st,en) dist[i] = inf;
	dist[st] = 0;
	queue<int> q;
	q.push(st);
	while (!q.empty())
	{
		int x = q.front();
		vis[x] = false;
		q.pop();
		for (int i = 0; i < g[x].size(); i++)
		if (g[x][i].flow && dist[g[x][i].v] > dist[x] + g[x][i].cost)
		{
			dist[g[x][i].v] = dist[x] + g[x][i].cost;
			pre[g[x][i].v].x = x;
			pre[g[x][i].v].y = i;
			if (!vis[g[x][i].v])
			{
				q.push(g[x][i].v);
				vis[g[x][i].v] = true;
			}
		}
	}
	return dist[en] < inf;
}
inline void addedge(int x, int y, int flow, int cost)
{
	int v1 = g[x].size();
	int v2 = g[y].size();
	mm.v = y;
	mm.flow = flow;
	mm.cost = cost;
	mm.rev = v2;
	g[x].push_back(mm);
	
	mm.v = x;
	mm.flow = 0;
	mm.rev = v1;
	mm.cost = -cost;
	g[y].push_back(mm);
}
int mincut(int x, int fw)
{
	if (x == st) return fw;
	int f = mincut(pre[x].x, min(fw, g[pre[x].x][pre[x].y].flow));
	g[pre[x].x][pre[x].y].flow -= f;
	g[x][g[pre[x].x][pre[x].y].rev].flow += f;
	return f;
}
void extKMP(int n, const char str[], int m, const char pat[], int A[], int B[])
{
   A[0] = m;
   int ind = 0, k = 1;
   while (ind + 1 < m && pat[ind + 1] == pat[ind]) ind++;
   A[1] = ind;
   for (int i = 2; i < m; i++) {
      if (i <= k + A[k] - 1 && A[i - k] + i < k + A[k]) {
         A[i] = A[i - k];
      } else {
         ind = max(0, k + A[k] - i);
         while (ind + i < m && pat[ind + i] == pat[ind]) ind++;
         A[i] = ind, k = i;
      }
   }
   ind = 0, k = 0;
   while (ind < n && str[ind] == pat[ind]) ind++;
   B[0] = ind;
   for (int i = 1; i < n; i++) {
      if (i <= k + B[k] - 1 && A[i - k] + i < k + B[k]) {
         B[i] = A[i - k];
      } else {
         ind = max(0, k + B[k] - i);
         while (ind + i < n && ind < m && str[ind + i] == pat[ind]) ind++;
         B[i] = ind, k = i;
      }
   }
}
int main()
{
	scanf("%d",&n);
	scanf("%s",str);
	scanf("%d",&m);
	st = 0;
	en = n + 1;
	int p;
	rep(ii,1,m)
	{
		scanf("%s",sp);
		scanf("%d",&p);
		int len = strlen(sp);
		extKMP(n, str, len, sp, A, B);
		FOR(i,0,n) if (B[i] == len)	addedge(i, i + len, 1, -p), A[i] = B[i] = 0;
	}
	int k;
	scanf("%d",&k);
	rep(i,1,n-1) addedge(i, i + 1, inf, 0);
	addedge(st, 1, k, 0);
	addedge(n, en, k, 0);
	LL ans = 0;
	while (spfa()) 
		ans += dist[en] * mincut(en, inf);
	cout << -ans << endl;
}