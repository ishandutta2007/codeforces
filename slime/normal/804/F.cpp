#include <bits/stdc++.h>
#define ll long long
#define maxn 5005 /*rem*/
#define mod 1000000007 
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
stack<int> s;
int low[10005],dfn[10005],k[10005];
bool vis[100005];
int idcnt = 0;
vi cur[maxn];
vi eg[maxn];
int dfcnt = 0;
void dfs(int u){
	dfn[u]=low[u]=++dfcnt;
//	cout << "DFS" << u << endl;
	s.push(u); vis[u]=true;
	for(auto v : eg[u]){
		if(!dfn[v]){
			dfs(v);
			low[u]=min(low[u],low[v]);
		}
		else if(vis[v])
			low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){
		idcnt++;
		while(int t=s.top()){
			vis[t]=false; s.pop();
			k[t]=idcnt;
			cur[idcnt].pb(t);
			if(t==u)
				break;
		}
	}
}
ll jc[maxn], bjc[maxn]; 
vi fl[maxn];
int n, a, b;
int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a % b);
}
char inp[1000005];
int dd[maxn];
vi cfl[maxn];
int cnt[maxn][2];
ll c(int a, int b) {
	if (b < 0 || b > a) return 0;
	return jc[a] * bjc[b] % mod * bjc[a - b] % mod; 
}
bool cmp(int a, int b) {
	return cnt[a][0] + cnt[a][1] < cnt[b][0] + cnt[b][1];
}
int main() {
	jc[0] = bjc[0] = 1;
	for (int i = 1; i < maxn; i++)
		jc[i] = jc[i - 1] * i % mod;
	for (int i = 1; i < maxn; i++)
		bjc[i] = ksm(jc[i], mod - 2);
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++) {
		scanf("%s", inp + 1);
		for (int j = 1; j <= n; j++)
			if (inp[j] == '1') eg[i].pb(j);//, cout << "EG" << i << ' '  << j << endl;
	}
	for (int i = 1; i <= n; i++) {
		int sz;
		scanf("%d", &sz);
		fl[i].resize(sz);
		scanf("%s", inp);
		for (int j = 0; j < sz; j++)
			fl[i][j] = inp[j] - '0'; // gangs
 	}
 	for (int i = 1; i <= n; i++)
		if (!dfn[i]) dfs(i);
//	cout << "AF" << ' ' << idcnt << endl;
 	for (int i = idcnt; i >= 1; i--) {
		int g = 0;
		for (auto v : cur[i])
	//		cout << "BL" << i << ' ' << v << endl, 
			g = gcd(g, fl[v].size());
		dd[i] = g;
		cfl[i].resize(dd[i]); //  
		for (auto v : cur[i]) 
			for (int j = 0; j < fl[v].size(); j++)
				if (fl[v][j]) cfl[i][j % g] = 1;
	}
	for (int i = idcnt; i >= 2; i--) {
		int ns = gcd(dd[i], dd[i - 1]);
		vi dfl(ns);
		for (int j = 0; j < dd[i]; j++)
			if (cfl[i][j])
				dfl[j % ns] = 1;
		for (int j = 0; j < dd[i - 1]; j++)
			if (dfl[j % ns])
				cfl[i - 1][j] = 1;
	}	

	for (int i = 1; i <= idcnt; i++)
		for (auto v : cur[i]) {
			for (int j = 0; j < fl[v].size(); j++)
				if (fl[v][j] == 0 && cfl[i][j % dd[i]] == 1) fl[v][j] = -1;
		}
	for (int i = 1; i <= n; i++) {
	//	cout << i << ' ' << fl[i].size() << endl;
		for (auto x : fl[i]) {
		//	cout << x << ' ';
			if (x == 1) cnt[i][0]++;
			else if (x == -1) cnt[i][1]++;
		}
	//	cout << endl;
	}
	vi id;
	for (int i = 1; i <= n; i++) id.pb(i);
	sort(id.begin(), id.end(), cmp);
	ll ans = 0;	
//	cout << "AF" << endl;
	for (int i = n - 1; i >= 0; i--) {
		int u = 0, v = 0;
		int x = id[i];
		for (int j = i + 1; j < n; j++) {
			int y = id[j];
			if (cnt[y][0] > cnt[x][0] + cnt[x][1]) u++;
			else v++;
		}
		int nu = max(0, u - (a - b));
		for (int s = nu; s <= u; s++)
			ans += c(u, s) * c(v, b - 1 - s), 
			ans %= mod;
	}
	cout << ans << endl;
	return 0;
}